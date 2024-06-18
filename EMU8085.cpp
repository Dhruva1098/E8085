#include "flag.h"
#include "instruction_set.h"

#include <iostream>
#include <string>
#include <vector>

int main() {
	MEMORY[0x0000] = 42;
	MOV(0x0000, (uint8_t)18);
	std::cout << (unsigned)MEMORY[0x0000];
}
