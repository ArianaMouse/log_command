#include "log_command.h"

void print(LogCommand& command) {
    command.print("Hello, Command Pattern!");
}

int main() {
    //Создание команды для консоли.
    ConsoleLogCommand console_cmd;

    //Создание команды для файла.
    FileLogCommand file_cmd("log.txt");

    //Вызывается функция print с разными командами.
    print(console_cmd);
    print(file_cmd);

    return 0;
}