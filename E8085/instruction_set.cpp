#include "instruction_set.hpp"
#include "flag.h"

#include <iostream>

uint8_t MEMORY[0xFFFF]; //__init__ memory 256x8 bytes
uint8_t GPR[6]; //general purpose registers
uint8_t SPR[3]; //special purpose registers
uint16_t program_counter;
uint16_t stack_pointer;

void MOV(uint8_t R, uint16_t M) {
    if (M <= 0xFFFF && R <= 5) { GPR[R] = MEMORY[M]; }
    else(std::cout << "ERROR: UNEXPECTED ADDRESS");
}
void MOV(uint16_t M, uint8_t data) {
    if (M <= 0xFFFF) { MEMORY[M] = data; }
    else(std::cout << "ERROR: UNEXPECTED ADDRESS");
}
void MVI(uint8_t R, uint8_t data) {
    if (R <= 5) { GPR[R] = data; }
    else(std::cout << "ERROR: UNEXPECTED ADDRESS");
}
void LDA(uint16_t M) {
    if (M <= 0xFFFF) { SPR[ACC] = MEMORY[M]; }
    else(std::cout << "ERROR: UNEXPECTED ADDRESS");
}
void LDAX(uint8_t R) {
    if (R <= 5) { SPR[ACC] = GPR[R]; }
    else(std::cout << "ERROR: UNEXPECTED ADDRESS");
}
void STA(uint16_t M) {
    if (M <= 0xFFFF) { MEMORY[M] = SPR[ACC]; }
    else(std::cout << "ERROR: UNEXPECTED ADDRESS");
}
