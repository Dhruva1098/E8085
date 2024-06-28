// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    std::unordered_map<uint8_t, instruction_void> instruction_map;
    std::cout << "hello world";
    instruction_map = {
        {1, MVI}
    };
    instruction_map[1];
}
