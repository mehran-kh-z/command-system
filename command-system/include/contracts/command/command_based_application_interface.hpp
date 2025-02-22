#pragma once
#include <types/utils.hpp>
#include <types/result.hpp>
#include <contracts/application_interface.hpp>

APP_NS

class CommandBasedApplicationInterface : public ApplicationInterface {
public:
  virtual Result<> register_command(const QString& command_name) = 0;
};

APP_NS_END
