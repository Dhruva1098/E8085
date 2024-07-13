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
    const auto& function_map = create_instruction_map();
    GPR[B] = 10;
    GPR[C] = 20;
    MEMORY[0x0000] = 13;
    // Input line

    for(int i = 0; i<=3; i++){
        std::string input_line;
        std::cout << "value at acc: " << (unsigned)SPR[ACC] << "\n";
        std::getline(std::cin, input_line);
    
        // Parse and execute
        parse_and_execute(input_line, function_map);
    }
    std::cout << (unsigned)SPR[ACC];
    return 0;
}
