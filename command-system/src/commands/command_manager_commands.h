#pragma once
#include <command_interface.h>
#include <iostream>

#include "type_utils.h"

APP_NS

class PrintCommand : public CommandInterface {
public:
  void execute() override {
    std::cout << "Executing print command." << std::endl;
  }
};

APP_NS_END
