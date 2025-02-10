#pragma once
#include <types/utils.h>

APP_NS

class CommandInterface {
public:
  virtual ~CommandInterface() = default;
  virtual void execute() = 0;
};

APP_NS_END
