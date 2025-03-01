#include <command/command_manager.hpp>
#include <exception/common.hpp>

APP_NS namespace command {

CommandManager::CommandManager(const std::shared_ptr<security::RBACCheckerInterface>& rbca_checker, std::shared_ptr<log::LoggerInterface> logger)
  : logger_(std::move(logger)), invoker_(rbca_checker) {
  logger_->error("Creating the default registry");
  add_registry(std::make_unique<CommandRegistry>("default"));
}

void CommandManager::add_registry(std::unique_ptr<CommandRegistry> registry) {
  registries_.emplace(registry->name(), std::move(registry));
}

void CommandManager::register_command(const CommandInstantiatorType& command_instantiator, const std::string& registry_name) {
  if (registries_.contains(registry_name)) {
    registries_[registry_name]->register_command(command_instantiator);
  }
  else {
    throw exception::RegistryNotFoundException(registry_name);
  }
}

void CommandManager::execute_command(const std::string& name) {
  /*for (auto& [_, registry] : registries_) {
    auto instantiator_type = registry->get_command(name);
    if (instantiator_type) {
      auto& [info, instantiator] = *instantiator_type;
      logger_->info("Executing command: " + info->name());

      //todo: execute using command_invoker & RBAC checker
      auto command = instantiator();
      invoker_.execute_command(command, info);
    }
  }*/
}

} APP_NS_END
