#include <command/command_info.hpp>

APP_NS namespace command {

CommandInfo::CommandInfo(const std::string& name) : name_(std::move(name)) {
}

const std::string& CommandInfo::name() {
  return name_;
}

} APP_NS_END
