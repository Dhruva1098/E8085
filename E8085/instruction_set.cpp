// Copyright 2024 Dhruva Sharma

#include "headers/instruction_set.hpp"

#include <iostream>

#include "headers/flag.h"

uint8_t MEMORY[0xFFFF];  // __init__ memory 256x8 bytes
uint8_t GPR[6];  // general purpose registers
uint8_t SPR[3];  // special purpose registers
uint16_t program_counter;
uint16_t stack_pointer;
_FLAG_ FLAG;
_STACK_ STACK;

// HELPER FUNCTIONS
bool aux_carry_addition_helper(const uint8_t& num1, const uint8_t& num2) {
    return (((num1 & 0X0F) + (num2 & 0x0F)) & 0x10) == 0x10;
}
bool aux_carry_subtraction_helper(const uint8_t& num1, const uint8_t& num2) {
    return static_cast<int>(num1 & 0x0F) - static_cast<int>(num2 & 0x0F) < 0;
}
bool parity_helper(uint8_t num) {
    bool parity;
    while (num) {
        parity = !parity;
        num = num & (num -1);
    }
    return parity;
}
// DATA TRANSFER INSTRUCTIONS
void MOV_RM(uint8_t R, uint16_t M) {  // working
    if (M <= 0xFFFF && R <= 5) { GPR[R] = MEMORY[M];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void MOV_MD(uint16_t M, uint8_t data) {  // working
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
void PUSH(uint8_t R) {
    if (R <= 5) { STACK.push_stack(GPR[R]);
    } else { std::cout << "ERROR:UNEXPECTED ADDRESS"; }
}
void POP(uint8_t R) {
    if (R <= 5) { GPR[R] = STACK.pop_stack();
    } else { std::cout << "ERROR:UNEXPECTED ADDRESS"; }
}
// ARITHMETIC OPERATIONS
void ADD_R(const uint8_t& R) {
    if (aux_carry_addition_helper(SPR[ACC], GPR[R])) { FLAG.set_aux_carry(); }
    SPR[ACC] = SPR[ACC] + GPR[R];
    if (!SPR[ACC]) { FLAG.set_zero(); }
    if (SPR[ACC] & 0b10000000) { FLAG.set_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_sign(); }
}
