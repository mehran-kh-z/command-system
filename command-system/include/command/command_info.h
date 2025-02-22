#pragma once
#include <contracts/command_info_interface.h>

APP_NS namespace command {

class CommandInfo : public CommandInfoInterface {
public:
  PROP(QString, alias);
};

} APP_NS_END
