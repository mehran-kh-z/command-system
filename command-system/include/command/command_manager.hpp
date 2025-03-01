#pragma once
#include <types/common.hpp>
#include <contracts/log/logger_interface.hpp>
#include <contracts/security/rbac_checker_interface.hpp>
#include <service/service_locator.hpp>
#include <command/command_registry.hpp>
#include <command/command_history.hpp>
#include <command/command_invoker.hpp>
#include <command_system_global.hpp>

APP_NS namespace command {

/**
 * @brief Manages command registries and commands.
 *
 * This class is responsible for managing command registries and commands.
 * It provides methods for adding registries, registering commands, and executing commands.
 */
class COMMAND_SYSTEM_EXPORT CommandManager {
public:
  /**
   * @brief Constructs a new CommandManager.
   *
   * @param logger The logger to use. If not provided, the default logger is used.
   * @param rbca_checker The RBAC checker to use. If not provided, no security will be applied to commands.
   */
  CommandManager(
    const std::shared_ptr<security::RBACCheckerInterface>& rbca_checker = nullptr,
    std::shared_ptr<log::LoggerInterface> logger = service::ServiceLocator::get_service<log::LoggerInterface>());

  /**
   * @brief Adds a registry to the manager.
   *
   * Registries are used to group commands together.
   *
   * @param registry The registry to add.
   */
  void add_registry(std::unique_ptr<CommandRegistry> registry);

  /**
   * @brief Registers a command with the given name.
   *
   * The command is registered in the default registry.
   *
   * @param command_instantiator A function that instantiates the command.
   * @param registry_name The name of the registry to register the command in.
   * @throws std::runtime_error if the registry is not found.
   * @todo Replace the runtime_error with a custom exception type.
   */
  void register_command(const CommandInstantiatorType& command_instantiator, const std::string& registry_name = "default");

  /**
   * @brief Executes a command with the given name.
   *
   * The command is executed in the first registry that contains the command.
   *
   * @param name The name of the command to execute
   * @todo Implement the command invoker.
   */
  void execute_command(const std::string& name);

private:
  /**
   * @brief The registries managed by this manager.
   */
  std::unordered_map<std::string, std::shared_ptr<CommandRegistry>> registries_;

  /**
   * @brief The logger used by this manager.
   */
  std::shared_ptr<log::LoggerInterface> logger_;

  /**
   * @brief The command invoker used to execute commands.
   */
  CommandInvoker invoker_;

  /**
   * @brief The command history used to store executed commands.
   */
  CommandHistory history_;
};

} APP_NS_END
