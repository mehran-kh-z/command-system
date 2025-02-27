#include <command/command_invoker.hpp>
#include <exception/common.hpp>

APP_NS namespace command {

CommandInvoker::CommandInvoker(std::shared_ptr<security::RBACCheckerInterface> rbac_checker) : rbac_checker_(std::move(rbac_checker)) {
}

Result CommandInvoker::execute_command(const std::unique_ptr<CommandInterface>& command, const std::shared_ptr<CommandInfoInterface>& info) {
  if (rbac_checker_ && !rbac_checker_->check_permission(info->permissions())) {
    return Err(exception::InvalidArgumentException("test"));
  }
  command->execute();

  return Ok();
}

} APP_NS_END
