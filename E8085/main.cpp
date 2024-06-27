// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    std::string instruction;
    std::vector<std::string> instructions;
    
    while (getline(std::cin, instruction) && !instruction.empty()) {
        instructions.push_back(instruction);
    }
    
    std::cout << "user has entered " << instructions.size() << " instructions";
}
