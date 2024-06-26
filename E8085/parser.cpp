// Copyright 2024 Dhruva Sharma

#include "headers/parser.h"

#include <sstream>
#include <iostream>

void parse_and_execute(
                       const std::string& input,
                       std::map<std::string,
                       std::function<void(const std::vector<std::string>&)>>& instruction_map) {
    std::istringstream iss(input);
    std::string instruction_name;
    iss >> instruction_name;
    std::vector<std::string> arguments;
    std::string arg;
    while (iss >> arg) {
        arguments.push_back(arg);
    }
    auto it = instruction_map.find(instruction_name);
    if (it != instruction_map.end()) {
        it->second(arguments);
    } else {
        std::cerr << "ERROR; function " << instruction_name << " not found." << std::endl;
    }
}
