#include <command/command_registry.h>
#include <QString>

APP_NS

CommandRegistry& CommandRegistry::instance() {
  static CommandRegistry instance;
  return instance;
}

void CommandRegistry::register_command(const std::string& name, std::shared_ptr<CommandInterface> command) {
  commands[name] = std::move(command);
}

void CommandRegistry::execute_command(const std::string& name) {
  if (commands.contains(name)) {
    commands[name]->execute();
  }
}

APP_NS_END
