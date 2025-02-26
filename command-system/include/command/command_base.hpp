#pragma once
#include <contracts/command/command_interface.hpp>
#include <command/command_info.hpp>
#include <command_system_global.hpp>

APP_NS namespace command {

class COMMAND_SYSTEM_EXPORT CommandBase : public CommandInterface {
public:
  void execute() override {
    
  }

  void undo() override {
    
  }

  [[nodiscard]] bool canUndo() const override {
    return false;
  }
};

} APP_NS_END
