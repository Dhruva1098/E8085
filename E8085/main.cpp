// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    MEMORY[0x0000] = 42;
    MOV(0x0000, (uint8_t)18);
    std::cout << (unsigned)MEMORY[0x0000];
}
