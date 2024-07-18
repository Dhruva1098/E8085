// Copyright 2024 Dhruva Sharma

#include "headers/parser.h"
#include "headers/instruction_map.h"

#include <sstream>
#include <iostream>

const auto& instruction_map = create_instruction_map();
void parse_and_execute(const std::string& input,
                     const std::map<std::string, std::function<void(const std::vector<std::string>&)>>& function_map) {
    std::istringstream iss(input);
    std::string function_name;
    iss >> function_name;
    std::vector<std::string> arguments;
    std::string arg;
    while (iss >> arg) {
        arguments.push_back(arg);
    }
    auto it = function_map.find(function_name);
    if (it != function_map.end()) {
        it->second(arguments);  // Call the function with arguments
    } else {
        std::cerr << "Error: Function " << function_name << " not found." << std::endl;
    }
}
void parse_and_execute_vector(const std::vector<std::string>& instruction_vector) {
    for(auto i: instruction_vector) {
        parse_and_execute(i, instruction_map);
    }
}
