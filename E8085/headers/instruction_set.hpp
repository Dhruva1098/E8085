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
    _MOV_RM = 0,
    _MVI_MD,
    _LDA,
    _LDAX,
    _LHLD,
    _STA,
    _STAX,
    _SPHL,
    _PUSH,
    _POP,
    _ADD_R,
    _ADD_M,
    _ADI,
    _ACI,
    _ADC,
    _AMC
};

void MOV_RM(const uint8_t& R, const uint16_t& M);
void MOV_MD(const uint16_t& M, const uint8_t& data);
void MVI(const uint8_t& R, const uint8_t& data);
void LDA(const uint16_t& M);
void LDAX(const uint8_t& R);
void LHLD(const uint16_t& M);
void STA(const uint16_t& M);
void STAX(const uint8_t& R);
void SPHL();
void PCHL();
// STACK OPERATIONS
void PUSH(uint8_t R);
void POP(uint8_t R);
// ARITHMETIC OPERATIONS
void ADD_R(const uint8_t& R);
void ADD_M(const uint16_t& M);
void ADI(const uint8_t& data);
void ACI(const uint8_t& data);
void ADC(const uint8_t& R);
void AMC(const uint16_t& M);

#endif  // E8085_HEADERS_INSTRUCTION_SET_HPP_
