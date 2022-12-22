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
#ifndef REACH_CORE_PLUGINS_IMPL_MULTIPLICATIVE_FACTORY_H
#define REACH_CORE_PLUGINS_IMPL_MULTIPLICATIVE_FACTORY_H

#include "pluginlib/class_loader.hpp"
#include "reach_core/plugins/evaluation_base.h"

namespace reach {
namespace plugins {

class SumFactory : public EvaluationBase {
 public:
  SumFactory();

  ~SumFactory() {
    for (auto& ev_pl : eval_plugins_) {
      ev_pl.reset();
    }
  }

  virtual bool initialize(
      std::string& name, rclcpp::Node::SharedPtr node,
      std::shared_ptr<const moveit::core::RobotModel> model) override;

  virtual double calculateScore(
      const std::map<std::string, double>& pose) override;

 private:
  std::vector<EvaluationBasePtr> eval_plugins_;

  pluginlib::ClassLoader<EvaluationBase> class_loader_;
};

}  // namespace plugins
}  // namespace reach

#endif  // REACH_CORE_PLUGINS_IMPL_MULTIPLICATIVE_FACTORY_H
