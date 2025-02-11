#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <command/command_interface.h>
#include <command_system_global.h>
#include <types/utils.h>

APP_NS

class COMMAND_SYSTEM_EXPORT CommandRegistry {
public:
  static CommandRegistry& instance();

  void register_command(const std::string& name, std::shared_ptr<CommandInterface> command);

  void execute_command(const std::string& name);

private:
  std::unordered_map<std::string, std::shared_ptr<CommandInterface>> commands;
};

APP_NS_END
