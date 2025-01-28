// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"
#include "headers/parser.h"
#include "headers/instruction_map.h"

int main() {
    // Create the function map
    GPR[B] = 10;
    GPR[C] = 20;
    MEMORY[0x0000] = 13;
    // Input line
    std::vector<std::string> instructions;
    std::cout << "Instructions start from 0000" << std::endl;
    while (true) {
        std::string input_line;
        std::getline(std::cin, input_line);
        if (input_line == "exit") break;
        instructions.push_back(input_line);
    }
    parse_and_execute_vector(instructions);
    std::cout << (unsigned)SPR[ACC];
}
