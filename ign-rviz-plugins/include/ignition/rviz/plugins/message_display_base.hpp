// Copyright (c) 2020 Sarathkrishnan Ramesh
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef IGNITION__RVIZ__PLUGINS__MESSAGE_DISPLAY_BASE_HPP_
#define IGNITION__RVIZ__PLUGINS__MESSAGE_DISPLAY_BASE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <string>

namespace ignition
{
namespace rviz
{
namespace plugins
{
class MessageDisplayBase
{
public:
  MessageDisplayBase() {}
  virtual ~MessageDisplayBase() {}

  /**
   * @brief ROS Visualzation plugin initialization function
   * @param ROS Node shared pointer
   * @throws anything rclcpp::exceptions::throw_from_rcl_error can throw.
   */
  virtual void initialize(rclcpp::Node::SharedPtr) = 0;
};

template<typename MessageType>
class MessageDisplay : public MessageDisplayBase
{
protected:
  typename rclcpp::Subscription<MessageType>::SharedPtr subscriber;
  rclcpp::Node::SharedPtr node;
  std::string topic_name;

public:
  MessageDisplay() {}
  virtual ~MessageDisplay() {}

  /**
   * @brief ROS subscriber callback function
   * @param ROS message type shared pointer
   * @throws anything rclcpp::exceptions::throw_from_rcl_error can throw.
   */
  virtual void callback(typename MessageType::SharedPtr) = 0;

  /**
   * @brief Set ROS subscriber topic
   * @param ROS topic name
   */
  virtual void setTopic(std::string) = 0;
};
}  // namespace plugins
}  // namespace rviz
}  // namespace ignition

#endif  // IGNITION__RVIZ__PLUGINS__MESSAGE_DISPLAY_BASE_HPP_
