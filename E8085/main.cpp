// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    for(auto& func : instruction_set) {
        func();
        std::cout << static_cast<unsigned>(MEMORY[0x0000]) << "\n" << GPR[B];
    }
}
