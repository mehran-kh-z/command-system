#pragma once
#include <types/utils.h>
#include <types/result.h>
#include <contracts/application_interface.h>

APP_NS

class CommandBasedApplicationInterface : public ApplicationInterface {
public:
  Result<> register_command(const QString& command_name) = 0;
};

APP_NS_END
