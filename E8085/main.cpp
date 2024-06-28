// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    auto it1 = instruction_map.find(3);
    if(it1 != instruction_map.end()) {
        std::invoke(it1->second, 2, 4);
    }
}
