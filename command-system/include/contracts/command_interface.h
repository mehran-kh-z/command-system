#pragma once
#include <types/common.h>
#include <contracts/command_info_interface.h>
#include <command_system_global.h>

APP_NS namespace command {

/**
 * @brief The CommandInterface class is the base class for all commands.
 */
class COMMAND_SYSTEM_EXPORT CommandInterface {
public:
  /**
   * @brief info is the command information.
   */
  IPROP(CommandInfoInterface, info);

  /**
   * @brief CommandInterface constructor.
   */
  virtual ~CommandInterface() = default;

  /**
   * @brief execute is the method that will be called to execute the command.
   */
  virtual void execute() = 0;
};

} APP_NS_END
