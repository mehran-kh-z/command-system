#pragma once
#include <types/utils.hpp>
#include <contracts/security/permission_list_interface.hpp>
#include <string>

APP_NS namespace command {

class CommandInfoInterface {
  IPROP(std::string, alias);

public:
  virtual const std::string& name() = 0;

  virtual const security::PermissionListInterface& permissions() const = 0;

  virtual ~CommandInfoInterface() = default;
};

} APP_NS_END
