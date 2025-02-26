#pragma once
#include <types/common.hpp>
#include <contracts/log/logger_interface.hpp>
#include <command_system_global.hpp>

APP_NS namespace command {

class COMMAND_SYSTEM_EXPORT CommandExecutionContext {
public:
  IPROP(log::LoggerInterface, logger);
};

} APP_NS_END
