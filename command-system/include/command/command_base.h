#pragma once
#include <contracts/command_interface.h>
#include <command/command_info.h>

APP_NS namespace command {

class CommandBase : public CommandInterface {
public:
  IPROP_IMPL(CommandInfoInterface, info, CommandInfo);
};

} APP_NS_END
