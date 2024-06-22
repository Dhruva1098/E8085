// Copyright 2024 Dhruva Sharma

#include "headers/instruction_set.hpp"

#include <iostream>

#include "headers/flag.h"

uint8_t MEMORY[0xFFFF];  // __init__ memory 256x8 bytes
uint8_t GPR[6];  // general purpose registers
uint8_t SPR[3];  // special purpose registers
uint16_t program_counter;
uint16_t stack_pointer;
_STACK_ STACK;

void MOV(uint8_t R, uint16_t M) {  // working
    if (M <= 0xFFFF && R <= 5) { GPR[R] = MEMORY[M];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void MOV(uint16_t M, uint8_t data) {  // working
    if (M <= 0xFFFF) { MEMORY[M] = data;
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void MVI(uint8_t R, uint8_t data) {  // working
    if (R <= 5) { GPR[R] = data;
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void LDA(uint16_t M) {  // working
    if (M <= 0xFFFF) { SPR[ACC] = MEMORY[M];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void LDAX(uint8_t R) {  // working
    if (R <= 5) { SPR[ACC] = GPR[R];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void LHLD(uint16_t M) {  // working
    if (M <= 0xFFFF) { GPR[H] = M;
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void STA(uint16_t M) {  // working
    if (M <= 0xFFFF) { MEMORY[M] = SPR[ACC];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void STAX(uint8_t R) {  // working
    if (R == B || R == D || R == H) { SPR[ACC] = (uint8_t)MEMORY[(uint16_t)GPR[R]];
    } else {std::cout << "ERROR: INVALID OPERAND. Expected input B,D,R";}
}
void SPHL() {  // working
    stack_pointer = (uint16_t)GPR[H];
}
// STACK OPERATIONS
void PUSH(uint8_t R){
    if (R <= 5) { STACK.push_stack(GPR[R]);
    } else { std::cout << "ERROR:UNEXPECTED ADDRESS"; }
}
void POP(uint8_t R){
    if (R <= 5) { GPR[R] = STACK.pop_stack();
    } else { std::cout << "ERROR:UNEXPECTED ADDRESS"; }
}
