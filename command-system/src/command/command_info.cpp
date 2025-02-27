#include <command/command_info.hpp>

APP_NS namespace command {

CommandInfo::CommandInfo(std::string name, std::unique_ptr<security::PermissionListInterface>) : name_(std::move(name)) {}

const std::string& CommandInfo::name() {
  return name_;
}

const security::PermissionListInterface& CommandInfo::permissions() const {
  return *permissions_;
}

} APP_NS_END
