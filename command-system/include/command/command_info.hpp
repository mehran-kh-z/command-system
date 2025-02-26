#pragma once
#include <contracts/command/command_info_interface.hpp>
#include <command_system_global.hpp>

APP_NS namespace command {

class COMMAND_SYSTEM_EXPORT CommandInfo : public CommandInfoInterface {
  IPROP_IMPL(std::string, alias);

public:
  CommandInfo(const std::string& name);

  const std::string& name() override;

private:
  std::string name_;
};

} APP_NS_END
