#pragma once
#include <contracts/command/command_interface.hpp>
#include <command/command_info.hpp>

APP_NS namespace command {

class CommandBase : public CommandInterface {
public:
  IPROP_IMPL(CommandInfoInterface, info, CommandInfo);
};

} APP_NS_END
