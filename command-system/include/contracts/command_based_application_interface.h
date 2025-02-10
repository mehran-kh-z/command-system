#pragma once
#include <types/utils.h>

APP_NS

class CommandBasedApplicationInterface : public ApplicationInterface {
public:
  void register_command(const QString& command_name) = 0;
};

APP_NS_END
