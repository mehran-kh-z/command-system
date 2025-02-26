#pragma once
#include <types/utils.hpp>
#include <contracts/command/command_info_interface.hpp>
#include <contracts/command/command_interface.hpp>
#include <memory>

APP_NS namespace command {

#define COMMAND_NAMESPACE(command_namespace) namespace command_namespace {  ///< Start of command namespace.
#define COMMAND_NAMESPACE_END }  ///< End of command namespace.

} APP_NS_END

/**
 * @brief A type that instantiates a command.
 * @todo Change NS::command::CommandInfoInterface container to std::unique_ptr instead of std::shared_ptr.
 */
  using CommandInstantiatorType = std::tuple<std::shared_ptr<NS::command::CommandInfoInterface>, std::function<std::unique_ptr<NS::command::CommandInterface>()>>;
