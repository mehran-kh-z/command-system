#pragma once
#include <types/utils.hpp>
#include <string>

APP_NS namespace command {

class CommandInfoInterface {
public:
  IPROP(std::string, alias);

  virtual const std::string& name() = 0;

  virtual ~CommandInfoInterface() = default;
};

} APP_NS_END
