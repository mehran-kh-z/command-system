#pragma once
#include <types/common.hpp>

APP_NS namespace command {

class CommandInfoInterface {
public:
  IPROP(QString, alias);

  ~CommandInfoInterface() = default;
};

} APP_NS_END
