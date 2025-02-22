#pragma once
#include <command/common.hpp>
#include <iostream>

APP_NS

class PrintCommand : public command::CommandBase {
public:
  void execute() override {
    std::cout << "Executing print command." << std::endl;
  }
};

APP_NS_END
