#pragma once
#include <command/common.hpp>
#include <command_system_global.hpp>
#include <string>
#include <unordered_map>

APP_NS namespace command {

class COMMAND_SYSTEM_EXPORT CommandRegistry {
  PROP(std::string, name);

public:
  CommandRegistry(std::string name);

  void register_command(const CommandInstantiatorType& command_instantiator);

  const CommandInstantiatorType* get_command(const std::string& name);

private:
  std::unordered_map<std::string, CommandInstantiatorType> commands_;
};

} APP_NS_END
