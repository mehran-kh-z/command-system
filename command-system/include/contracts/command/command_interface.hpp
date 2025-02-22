#pragma once
#include <types/common.hpp>
#include <contracts/command/command_info_interface.hpp>
#include <command_system_global.hpp>

APP_NS namespace command {

/**
 * @brief The CommandInterface class is the base class for all commands.
 */
class COMMAND_SYSTEM_EXPORT CommandInterface {
public:
  /**
   * @brief Info is the command information.
   */
  IPROP(CommandInfoInterface, info);

  /**
   * @brief CommandInterface constructor.
   */
  virtual ~CommandInterface() = default;

  /**
   * @brief Execute is the method that will be called to execute the command.
   */
  virtual void execute() = 0;

  /**
   * @brief Undo is the method that will be called to undo the command.
   */
  virtual void undo() = 0;
};

} APP_NS_END
