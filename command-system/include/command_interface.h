#pragma once

namespace Evoteam {

class CommandInterface {
public:
  virtual ~CommandInterface() = default;
  virtual void execute() = 0;
};

} // namespace Evoteam
