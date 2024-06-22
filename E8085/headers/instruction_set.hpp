// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_INSTRUCTION_SET_HPP_
#define E8085_HEADERS_INSTRUCTION_SET_HPP_

#include <iostream>
#include <vector>

extern uint8_t MEMORY[0xFFFF];  // __init__ memory 256x8 bytes
extern uint8_t GPR[6];  // general purpose registers
extern uint8_t SPR[3];  // special purpose registers
extern uint16_t program_counter;
extern uint16_t stack_pointer;

class _STACK_{
 public:
    std::vector<uint16_t> stack_array;
    _STACK_(): stack_array({}) {}
    void push_stack(const uint16_t& item) {
        stack_array.push_back(item);
    }
    uint16_t pop_stack() {
        if (stack_array.empty()) {
            throw std::out_of_range("ERROR:EMPTY STACK \n");
        } else {
            uint16_t last = stack_array.back();
            stack_array.pop_back();
            return last;
        }
    }
};

enum{
    _MOV = 0,
    _MVI,
    _LDA,
    _LDAX,
    _LHLD,
    _STA,
    _STAX,
    _SPHL,
    _PUSH,
    _POP
};

void MOV(uint8_t R, uint16_t M);
void MOV(uint16_t M, uint8_t data);
void MVI(uint8_t R, uint8_t data);
void LDA(uint16_t M);
void LDAX(uint8_t R);
void LHLD(uint16_t M);
void STA(uint16_t M);
void STAX(uint8_t R);
void SPHL();
void PCHL();
// STACK OPERATIONS
void PUSH(uint8_t R);
void POP(uint8_t R);
#endif  // E8085_HEADERS_INSTRUCTION_SET_HPP_
