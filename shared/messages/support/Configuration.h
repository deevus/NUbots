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

#ifndef MESSAGES_SUPPORT_CONFIGURATION_H_
#define MESSAGES_SUPPORT_CONFIGURATION_H_

#include <nuclear>
#include <yaml-cpp/yaml.h>

namespace messages {
    namespace support {

        /**
         * TODO document
         *
         * @author Trent Houliston
         */
        struct Configuration {
            std::string name;
            YAML::Node config;

            Configuration(const std::string& name, YAML::Node config) : name(name), config(config) {};

            YAML::Node operator [] (const std::string& key) {
                return config[key];
            }

            const YAML::Node operator [] (const std::string& key) const {
                return config[key];
            }

            YAML::Node operator [] (const char* key) {
                return config[key];
            }

            const YAML::Node operator [] (const char* key) const {
                return config[key];
            }

            YAML::Node operator [] (size_t index) {
                return config[index];
            }

            const YAML::Node operator [] (size_t index) const {
                return config[index];
            }
        };

        /**
         * TODO document
         *
         * @author Trent Houliston
         */
        struct ConfigurationConfiguration {
            std::string path;
            std::shared_ptr<NUClear::threading::Reaction> reaction;
        };

    }  // support
}  // messages

namespace NUClear {
    namespace dsl {
        namespace operation {
            template <>
            struct DSLProxy<messages::support::Configuration> {

                template <typename DSL, typename TFunc>
                static inline threading::ReactionHandle bind(Reactor& reactor, const std::string& label, TFunc&& callback, const std::string& path) {

                    auto reaction = util::generate_reaction<DSL, messages::support::Configuration>(reactor, label, std::forward<TFunc>(callback));
                    threading::ReactionHandle handle(reaction.get());

                    // Send our configuration out
                    reactor.powerplant.emit<word::emit::Direct>(std::make_unique<messages::support::ConfigurationConfiguration>(messages::support::ConfigurationConfiguration {
                        path,
                        std::move(reaction)
                    }));

                    // Return our handles
                    return handle;
                }

                template <typename DSL>
                static inline std::unique_ptr<messages::support::Configuration> get(threading::ReactionTask&) {

                    // Return our thread local variable
                    return std::make_unique<messages::support::Configuration>("temp!", YAML::Node());
                }

            };
        }
    }
}

#endif
