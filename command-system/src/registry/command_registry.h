#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <command_interface.h>
#include <command_system_global.h>

namespace Evoteam {

class COMMAND_SYSTEM_LIBRARY CommandRegistry {
public:
  static CommandRegistry& instance();

  void register_command(const std::string& name, std::shared_ptr<CommandInterface> command);

  void execute_command(const std::string& name);

private:
  std::unordered_map<std::string, std::shared_ptr<CommandInterface>> commands;
};

}
