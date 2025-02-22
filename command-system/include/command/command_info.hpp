#pragma once
#include <contracts/command/command_info_interface.hpp>

APP_NS namespace command {

class CommandInfo : public CommandInfoInterface {
public:
  PROP(QString, alias);
};

} APP_NS_END
