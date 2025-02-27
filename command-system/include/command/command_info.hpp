#pragma once
#include <contracts/command/command_info_interface.hpp>
#include <command_system_global.hpp>

APP_NS namespace command {

class COMMAND_SYSTEM_EXPORT CommandInfo : public CommandInfoInterface {
  IPROP_IMPL(std::string, alias);

public:
  CommandInfo(std::string name, std::unique_ptr<security::PermissionListInterface> = nullptr);

  const std::string& name() override;

  const security::PermissionListInterface& permissions() const override;

private:
  std::string name_;

  std::unique_ptr<security::PermissionListInterface> permissions_;
};

} APP_NS_END
