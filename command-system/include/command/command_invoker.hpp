#pragma once
#include <types/common.hpp>
#include <contracts/command/command_interface.hpp>
#include <contracts/security/rbac_checker_interface.hpp>

APP_NS namespace command {

class CommandInvoker {
public:
  /**
   * @brief Constructs a new CommandInvoker.
   *
   * @param rbac_checker The RBAC checker to use. If not provided, no security will be applied to commands.
   */
  CommandInvoker(std::shared_ptr<security::RBACCheckerInterface> rbac_checker = nullptr);

  Result execute_command(const std::unique_ptr<CommandInterface>& command, const std::shared_ptr<CommandInfoInterface>& info);

private:
  std::shared_ptr<security::RBACCheckerInterface> rbac_checker_;
};

} APP_NS_END
