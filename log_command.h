#pragma once

#include <fstream>
#include <iostream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

//Вывод в консоль.
class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

//Вывод в файл.
class FileLogCommand : public LogCommand {
public:
    //В конструкторе принимаеится путь к файлу.
    explicit FileLogCommand(std::string file_path)
        : file_path_(std::move(file_path)) {
    }

    void print(const std::string& message) override {
        //Открываем файл в режиме добавления.
        std::ofstream file(file_path_, std::ios::app);
        if (file.is_open()) {
            file << message << std::endl;
        }
        else {
            std::cerr << "Failed to open file: " << file_path_ << std::endl;
        }
    }

private:
    std::string file_path_;
};