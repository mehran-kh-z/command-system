#pragma once
#include <types/common.hpp>
#include <command/command_registry.hpp>

APP_NS namespace command {

class CommandManager {
public:
  CommandManager();

  void add_registry(std::unique_ptr<CommandRegistry> registry);

  void execute_command(const std::string& name);

private:
  std::vector<std::unique_ptr<CommandRegistry>> registries;
};

} APP_NS_END
