// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_INSTRUCTION_SET_HPP_
#define E8085_HEADERS_INSTRUCTION_SET_HPP_

#include <iostream>

extern uint8_t MEMORY[0xFFFF];  // __init__ memory 256x8 bytes
extern uint8_t GPR[6];  // general purpose registers
extern uint8_t SPR[3];  // special purpose registers
extern uint16_t program_counter;
extern uint16_t stack_pointer;

enum{
    _MOV = 0,
    _MVI,
    _LDA,
    _LDAX,
    _STA,
    _STAX,
    _SPHL
};

void MOV(uint8_t R, uint16_t M);
void MOV(uint16_t M, uint8_t data);
void MVI(uint8_t R, uint8_t data);
void LDA(uint16_t M);
void LDAX(uint8_t R);
void STA(uint16_t M);
void STAX(uint8_t R);
void SPHL();

#endif  // E8085_HEADERS_INSTRUCTION_SET_HPP_
