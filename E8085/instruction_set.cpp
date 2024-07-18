// Copyright 2024 Dhruva Sharma

#include "headers/instruction_set.hpp"

#include <limits.h>
#include <iostream>
#include <sstream>

#include "headers/flag.h"

uint8_t MEMORY[0xFFFF];  // __init__ memory 256x8 bytes
uint8_t GPR[6];  // general purpose registers
uint8_t SPR[3];  // special purpose registers
uint16_t program_counter;
uint16_t stack_pointer;

_FLAG_ FLAG;
_STACK_ STACK;

// HELPER FUNCTIONS
uint16_t string_to_hex(const std::string& str) {
    uint16_t hex_format;
    std::stringstream ss;
    ss << str;
    ss >> std::hex >> hex_format;
    return hex_format;
}


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
    } return parity;
}
bool carry_addition_helper(const uint8_t& num1, const uint8_t& num2) {
    return ((num2 < 0 && num1 < 0 - num2) || (num2 > 0 && num1 > UINT8_MAX - num2));
}
bool carry_subtraction_helper(const uint8_t& num1, const uint8_t num2) {
    return ((num2 < 0 && num1 > UINT8_MAX + num2) || (num2 > 0 && num1 < 0 + num2));
}
// DATA TRANSFER INSTRUCTIONS
void MOV_RM(const uint8_t& R, const uint16_t& M) {  // working
    if (M <= 0xFFFF && R <= 5) { GPR[R] = MEMORY[M];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void MOV_MD(const uint16_t& M, const uint8_t& data) {  // working
    if (M <= 0xFFFF) { MEMORY[M] = data;
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void MVI(const uint8_t& R, const uint8_t& data) {  // working
    if (R <= 5) { GPR[R] = data;
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void LDA(const uint16_t& M) {  // working
    if (M <= 0xFFFF) { SPR[ACC] = MEMORY[M];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void LDAX(const uint8_t& R) {  // working
    if (R <= 5) { SPR[ACC] = GPR[R];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void LHLD(const uint16_t& M) {  // working
    if (M <= 0xFFFF) { GPR[H] = M;
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void STA(const uint16_t& M) {  // working
    if (M <= 0xFFFF) { MEMORY[M] = SPR[ACC];
    } else {std::cout << "ERROR: UNEXPECTED ADDRESS";}
}
void STAX(const uint8_t& R) {  // working
    if (R == B || R == D || R == H) { SPR[ACC] = static_cast<uint8_t>(MEMORY[static_cast<uint16_t>(GPR[R])]);
    } else {std::cout << "ERROR: INVALID OPERAND. Expected input B,D,R";}
}
void SPHL() {  // working
    stack_pointer = static_cast<uint16_t>(GPR[H]);
}
void PCHL() {
    program_counter = static_cast<uint16_t>(GPR[H]);
}
// STACK OPERATIONS
void PUSH(const uint8_t& R) {
    if (R <= 5) { STACK.push_stack(GPR[R]);
    } else { std::cout << "ERROR:UNEXPECTED ADDRESS"; }
}
void POP(const uint8_t& R) {
    if (R <= 5) { GPR[R] = STACK.pop_stack();
    } else { std::cout << "ERROR:UNEXPECTED ADDRESS"; }
}
// ARITHMETIC OPERATIONS
void ADD_R(const uint8_t& R) {
    if (aux_carry_addition_helper(SPR[ACC], GPR[R])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_addition_helper(SPR[ACC], GPR[R])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    SPR[ACC] = SPR[ACC] + GPR[R];  // store in acc itself
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ADD_M(const uint16_t& M) {
    if (aux_carry_addition_helper(SPR[ACC], MEMORY[M])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_addition_helper(SPR[ACC], MEMORY[M])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    SPR[ACC] = SPR[ACC] + MEMORY[M];  // store in acc itself
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ADI(const uint8_t& data) {
    if (aux_carry_addition_helper(SPR[ACC], data)) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_addition_helper(SPR[ACC], data)) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    SPR[ACC] = SPR[ACC] + data;  // store in acc itself
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ACI(const uint8_t& data) {
    uint8_t tempCarry = 0;
    if (FLAG.get_carry()) { tempCarry = 1; }
    if (aux_carry_addition_helper(SPR[ACC], data)) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_addition_helper(SPR[ACC], data)) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (tempCarry) { SPR[ACC] = SPR[ACC] + data + 0x01;  // add with carry
    } else { SPR[ACC] = SPR[ACC] + data; }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ADC(const uint8_t& R) {
    uint8_t tempCarry = 0;
    if (FLAG.get_carry()) { tempCarry = 1; }
    if (aux_carry_addition_helper(SPR[ACC], GPR[R])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_addition_helper(SPR[ACC], GPR[R])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (tempCarry) { SPR[ACC] = SPR[ACC] + GPR[R] + 0x01;  // add with carry
    } else { SPR[ACC] = SPR[ACC] + GPR[R]; }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void AMC(const uint16_t& M) {
    uint8_t tempCarry = 0;
    if (FLAG.get_carry()) { tempCarry = 1; }
    if (aux_carry_addition_helper(SPR[ACC], MEMORY[M])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_addition_helper(SPR[ACC], MEMORY[M])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (tempCarry) { SPR[ACC] = SPR[ACC] + MEMORY[M] + 0x01;  // add with carry
    } else { SPR[ACC] = SPR[ACC] + MEMORY[M]; }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void SUB_R(const uint8_t& R) {
    if (aux_carry_subtraction_helper(SPR[ACC], GPR[R])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], GPR[R])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    SPR[ACC] = SPR[ACC] - GPR[R];  // store in acc itself
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void SUB_M(const uint16_t& M) {
    if (aux_carry_subtraction_helper(SPR[ACC], MEMORY[M])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], MEMORY[M])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    SPR[ACC] = SPR[ACC] - MEMORY[M];  // store in acc itself
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void SUI(const uint8_t& data) {
    if (aux_carry_subtraction_helper(SPR[ACC], data)) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], data)) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    SPR[ACC] = SPR[ACC] - data;  // store in acc itself
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void SBI(const uint8_t& data) {
    uint8_t tempCarry = 0;
    if (FLAG.get_carry()) { tempCarry = 1; }
    if (aux_carry_subtraction_helper(SPR[ACC], data)) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], data)) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (tempCarry) { SPR[ACC] = (SPR[ACC] + 0x10) - data;  // subtract with borrow
    } else { SPR[ACC] = SPR[ACC] + data; }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void SBB_R(const uint8_t& R) {
    uint8_t tempCarry = 0;
    if (FLAG.get_carry()) { tempCarry = 1; }
    if (aux_carry_subtraction_helper(SPR[ACC], GPR[R])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], GPR[R])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (tempCarry) { SPR[ACC] = (SPR[ACC] + 0x10) - GPR[R];  // subtract with borrow
    } else { SPR[ACC] = SPR[ACC] + GPR[R]; }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void SBB_M(const uint16_t& M) {
    uint8_t tempCarry = 0;
    if (FLAG.get_carry()) { tempCarry = 1; }
    if (aux_carry_subtraction_helper(SPR[ACC], MEMORY[M])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], MEMORY[M])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (tempCarry) { SPR[ACC] = (SPR[ACC] + 0x01) - MEMORY[M];  // subtract with borrow
    } else { SPR[ACC] = SPR[ACC] + MEMORY[M]; }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
//  LOGICAL INSTRUCTIONS
void CMP_R(const uint8_t& R) {
    if (aux_carry_subtraction_helper(SPR[ACC], GPR[R])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], GPR[R])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void CMP_M(const uint16_t& M) {
    if (aux_carry_subtraction_helper(SPR[ACC], MEMORY[M])) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], MEMORY[M])) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void CPI(const uint8_t& data) {
    if (aux_carry_subtraction_helper(SPR[ACC], data)) { FLAG.set_aux_carry();
    } else { FLAG.reset_aux_carry(); }
    if (carry_subtraction_helper(SPR[ACC], data)) { FLAG.set_carry();
    } else { FLAG.reset_carry(); }
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ANA_R(const uint8_t& R) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] & GPR[R];
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ANA_M(const uint16_t& M) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] & MEMORY[M];
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ANI(const uint8_t& data) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] & data;
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ORA_R(const uint8_t& R) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] | GPR[R];
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ORA_M(const uint16_t& M) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] | MEMORY[M];
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void ORI(const uint8_t& data) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] | data;
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void XRA_R(const uint8_t& R) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] ^ GPR[R];
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void XRA_M(const uint16_t& M) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] ^ MEMORY[M];
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void XRI(const uint8_t& data) {
    FLAG.reset_carry();
    FLAG.reset_aux_carry();
    SPR[ACC] = SPR[ACC] ^ data;
    if (!SPR[ACC]) { FLAG.set_zero();
    } else { FLAG.reset_zero(); }
    if (SPR[ACC] & 0x80) { FLAG.set_sign();
    } else { FLAG.reset_sign(); }
    if (parity_helper(SPR[ACC])) { FLAG.set_parity();
    } else { FLAG.reset_parity(); }
}
void CMC() {
    if (FLAG.get_carry()) { FLAG.reset_carry();
    } else { FLAG.set_carry(); }
}
void STC() {
    FLAG.set_carry();
}
// JUMP INSTRUCTIONS
uint16_t JMP(const uint16_t ins_addr) {
    return ins_addr;
}
uint16_t JC(uint16_t ins_addr) {
    if (FLAG.get_carry()) return ins_addr;
    else return -1;
}
