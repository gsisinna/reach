/*
 * Copyright 2019 Southwest Research Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MOVEIT_REACH_PLUGINS_KINEMATICS_UTILS_H
#define MOVEIT_REACH_PLUGINS_KINEMATICS_UTILS_H

#include <map>
#include <optional>
#include <string>

#include <rclcpp/rclcpp.hpp>

#include <moveit_msgs/msg/collision_object.hpp>
#include <reach_msgs/msg/reach_record.hpp>
#include <visualization_msgs/msg/interactive_marker.hpp>
#include <visualization_msgs/msg/marker.hpp>

namespace moveit_reach_plugins {
namespace utils {

/**
 * @brief createCollisionObject
 * @param mesh_filename
 * @param parent_link
 * @param object_name
 * @return
 */
moveit_msgs::msg::CollisionObject createCollisionObject(
    const std::string& mesh_filename, const std::string& parent_link,
    const std::string& object_name);

/**
 * @brief makeInteractiveMarker
 * @param r
 * @param frame
 * @param scale
 * @return
 */
visualization_msgs::msg::Marker makeVisual(
    const rclcpp::Node::SharedPtr node, const reach_msgs::msg::ReachRecord& r,
    const std::string& frame, const double scale,
    const std::string& ns = "reach",
    const std::optional<std::vector<float>>& color = {});

/**
 * @brief makeInteractiveMarker
 * @param r
 * @param frame
 * @param scale
 * @return
 */
visualization_msgs::msg::InteractiveMarker makeInteractiveMarker(
    const rclcpp::Node::SharedPtr node, const reach_msgs::msg::ReachRecord& r,
    const std::string& frame, const double scale);

/**
 * @brief makeMarker
 * @param pts
 * @param frame
 * @param scale
 * @param ns
 * @return
 */
visualization_msgs::msg::Marker makeMarker(
    const rclcpp::Node::SharedPtr node,
    const std::vector<geometry_msgs::msg::Point>& pts, const std::string& frame,
    const double scale, const std::string& ns = "");

/**
 * @brief validateInputMap
 * @param input
 * @param joint_names
 * @param revised_input
 * @return
 */
bool transcribeInputMap(const std::map<std::string, double>& input,
                        const std::vector<std::string>& joint_names,
                        std::vector<double>& revised_input);

}  // namespace utils
}  // namespace moveit_reach_plugins

#endif  // MOVEIT_REACH_PLUGINS_KINEMATICS_UTILS_H
