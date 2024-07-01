// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_INSTRUCTION_SET_HPP_
#define E8085_HEADERS_INSTRUCTION_SET_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>

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

void MOV_RM(const uint8_t& R, const uint16_t& M);  // RM
void MOV_MD(const uint16_t& M, const uint8_t& data);  // MD
void MVI(const uint8_t& R, const uint8_t& data);  // RD
void LDA(const uint16_t& M);  // M
void LDAX(const uint8_t& R);  // R
void LHLD(const uint16_t& M);  // M
void STA(const uint16_t& M);  // M
void STAX(const uint8_t& R);  // R
void SPHL();  // void
void PCHL();  // void
// STACK OPERATIONS
void PUSH(uint8_t R);  // R
void POP(uint8_t R);  // R
// ARITHMETIC OPERATIONS
void ADD_R(const uint8_t& R);  // R
void ADD_M(const uint16_t& M);  // M
void ADI(const uint8_t& data);  // D
void ACI(const uint8_t& data);  // D
void ADC(const uint8_t& R);  // R
void AMC(const uint16_t& M);  // M
void SUB_R(const uint8_t& R);  // R
void SUB_M(const uint16_t& M);  // M
void SUI(const uint8_t& data);  // D
void SBI(const uint8_t& data);  // D
void SBB_R(const uint8_t& R);  // R
void SBB_M(const uint16_t& M);  // M
void INX(const uint8_t& R);  // R
void DCX(const uint8_t& R);  // R
void DCR(const uint16_t& M);  // M
//  LOGICAL INSTRUCTIONS
void CMP_R(const uint8_t& R);  // R
void CMP_M(const uint16_t& M);  // M
void CPI(const uint8_t& data);  // D
void ANA_R(const uint8_t& R);  // R
void ANA_M(const uint16_t& M);  // M
void ANI(const uint8_t& data);  // D
void ORA_R(const uint8_t& R);  // R
void ORA_M(const uint16_t& M);  // M
void ORI(const uint8_t& data);  // D
void XRA_R(const uint8_t& R);  // R
void XRA_M(const uint16_t& M);  // M
void XRI(const uint8_t& data);  // D
void CMC();  // void
void STC();  // void

// Type aliases for functional pointers
using instruction_RM = std::function<void(uint8_t&, uint16_t&)>;
using instruction_MD = std::function<void(uint16_t&, uint8_t&)>;
using instruction_RD = std::function<void(uint8_t&, uint8_t&)>;
using instruction_M = std::function<void(uint16_t&)>;
using instruction_R = std::function<void(uint8_t&)>;
using instruction_D = std::function<void(uint8_t&)>;
using instruction_void = std::function<void()>;

#endif  // E8085_HEADERS_INSTRUCTION_SET_HPP_
