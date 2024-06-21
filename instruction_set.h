#include <iostream>

extern uint8_t MEMORY[0xFFFF]; //__init__ memory 256x8 bytes
extern uint8_t GPR[6]; //general purpose registers
extern uint8_t SPR[3]; //special purpose registers
extern uint16_t program_counter;
extern uint16_t stack_pointer;

enum {
    MOV = 0,
    MVI,
    LDA,
    LDAX,
    STA,
    XCHG,
    SPHL,
    PCHL,
    PUSH
}

void MOV(uint8_t R, uint16_t M);
void MOV(uint16_t M, uint8_t data);
void MVI(uint8_t R, uint8_t data);
void LDA(uint16_t M);
void LDAX(uint8_t R);
void STA(uint16_t M);
void XCHG(uint8_t R, uint8_t R);
void SPHL(); //HL -> SP
void PCHL(); //PC -> HL
void PUSH(uint8_t R);





