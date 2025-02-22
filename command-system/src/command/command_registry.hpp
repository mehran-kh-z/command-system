#pragma once
#include <types/utils.hpp>
#include <command/command_interface.hpp>
#include <command_system_global.hpp>
#include <string>
#include <unordered_map>
#include <memory>

APP_NS namespace command {

class COMMAND_SYSTEM_EXPORT CommandRegistry {
public:
  static CommandRegistry& instance();

  void register_command(const std::string& name, std::shared_ptr<CommandInterface> command);

  void execute_command(const std::string& name);

private:
  std::unordered_map<std::string, std::shared_ptr<CommandInterface>> commands;
};

} APP_NS_END
