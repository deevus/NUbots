/*
 * This file is part of the NUbots Codebase.
 *
 * The NUbots Codebase is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The NUbots Codebase is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the NUbots Codebase.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2013 NUBots <nubots@nubots.net>
 */

#ifndef MODULES_BEHAVIOUR_REFLEX_HeadController_H
#define MODULES_BEHAVIOUR_REFLEX_HeadController_H

#include <nuclear>
#include <armadillo>

namespace modules {
    namespace motion {

            /**
             * Executes a HeadController action.
             *
             * @author Josiah Walker
             */
            class HeadController : public NUClear::Reactor {
            private:
                const size_t id;
                double fastSpeed,slowSpeed,headYaw,headPitch,panTime,minYaw,maxYaw,minPitch,maxPitch,screenPadding,headGain,headTorque;
                arma::vec2 testGoal;

                double prevPitch,prevYaw;
                time_t lastPanEnd;
            public:
                explicit HeadController(std::unique_ptr<NUClear::Environment> environment);
                static constexpr const char* CONFIGURATION_PATH = "HeadController.yaml";
            };

    }  // motion 
}  // modules

#endif  // MODULES_BEHAVIOURS_REFLEX_HeadController_H

