// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"

int main() {
    MEMORY[0x0000] = 42;
    MOV((uint16_t)0x0001, 11);
    MVI(H, 0x01);
    MVI(L, 0x00);  // little endian, read as LH not HL
    LDAX(B);
    STA(0x0001);
    STAX(B);
    SPHL();
    std::cout << (unsigned)SPR[ACC] << "\n"<< (unsigned)GPR[B]
    << "\n" << (unsigned)MEMORY[0x0001] << "\n" <<
    (unsigned)stack_pointer << "\n";
}
