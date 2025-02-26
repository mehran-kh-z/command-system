#include <command/command_registry.hpp>

APP_NS namespace command {

CommandRegistry::CommandRegistry(std::string name) : name_(std::move(name)) {
}

void CommandRegistry::register_command(const CommandInstantiatorType& command_instantiator) {
  auto& [info, instantiator] = command_instantiator;
  commands_[info->name()] = command_instantiator;
}

const CommandInstantiatorType* CommandRegistry::get_command(const std::string& name) {
  if (commands_.contains(name)) {
    return &commands_[name];
  }
  return nullptr;
}

} APP_NS_END
