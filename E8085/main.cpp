// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"
#include "headers/parser.h"

int main() {
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> instruction_map;
    instruction_map["MVI"] = [](const std::vector<std::string>& args) {
        if (args.size() >= 2) {
            uint8_t a = (uint8_t)std::stoi(args[0]);
            uint8_t b = (uint8_t)std::stoi(args[1]);
            MVI(a, b);
        } else {
            std::cerr << "ERROR: MVI expects exactly 2 arguments";
        }
    };
    std::string input_line;
    std::getline(std::cin, input_line);
    parse_and_execute(input_line, instruction_map);
    std::cout << "register B contains: " << (unsigned)GPR[2] << std::endl;
    return 0;
}
