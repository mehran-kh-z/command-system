#include <command/command_manager.hpp>
#include "command_manager.hpp"

APP_NS namespace command {

CommandManager::CommandManager() {
}

void CommandManager::add_registry(std::unique_ptr<CommandRegistry> registry) {
  registries.push_back(std::move(registry));
}

void CommandManager::execute_command(const std::string& name) {
  for (auto& registry : registries) {
    registry->execute_command(name);
  }
}

} APP_NS_END
