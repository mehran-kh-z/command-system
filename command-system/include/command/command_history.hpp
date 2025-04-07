#pragma once
#include <types/common.hpp>
#include <contracts/command/command_interface.hpp>

APP_NS namespace command {

class CommandHistory {
public:
  [[nodiscard]] bool can_undo() const;

  [[nodiscard]] bool can_redo() const;

  void push(std::shared_ptr<CommandInterface> command);
};

} APP_NS_END
