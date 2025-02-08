#pragma once
#include <command_interface.h>
#include <iostream>

namespace Evoteam {

class PrintCommand : public CommandInterface {
public:
  void execute() override {
    std::cout << "Executing print command." << std::endl;
  }
};

} // namespace Evoteam
