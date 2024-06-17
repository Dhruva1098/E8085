#include "flag.h"

#include <iostream>

uint8_t MEMORY[0xFF]; //__init__ memory 256x8 bytes
uint8_t GPR[6]; //general purpose registers
uint8_t SPR[3]; //special purpose registers
uint16_t program_counter;
uint16_t stack_pointer;

int main() {
}
