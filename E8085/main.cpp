// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    MEMORY[0x0000] = 42;
    MOV_MD((uint16_t)0x0001, 11);
    LHLD(0x0001);
    LDAX(B);
    STA(0x0001);
    STAX(B);
    SPHL();
    std::cout << (unsigned)SPR[ACC] << "\n"<< (unsigned)GPR[B]
    << "\n" << (unsigned)MEMORY[0x0001] << "\n" <<
    (unsigned)stack_pointer << "\n";
}
