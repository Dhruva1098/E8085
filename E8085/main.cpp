//
//  main.cpp
//  E8085
//
//  Created by Dhruva Sharma on 21/06/24.
//

#include "flag.h"
#include "instruction_set.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    MEMORY[0x0000] = 42;
    MOV(0x0000, (uint8_t)18);
    std::cout << (unsigned)MEMORY[0x0000];
}
