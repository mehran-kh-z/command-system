#pragma once
#include <types/utils.h>
#include <command_system_global.h>

APP_NS

class COMMAND_SYSTEM_EXPORT CommandInterface {
public:
  virtual ~CommandInterface() = default;
  virtual void execute() = 0;
};

APP_NS_END
