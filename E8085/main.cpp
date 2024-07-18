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

    while (1) {
        std::string input_line;
        std::getline(std::cin, input_line);
        if (input_line != "exit") break;
    }
    std::cout << (unsigned)SPR[ACC];
    return 0;
}
