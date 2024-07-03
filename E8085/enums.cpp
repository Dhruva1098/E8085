// Copyright 2024 Dhruva Sharma

#include "headers/enums.h"

int string_to_enum(const std::string& str) {
    if (str == "B") return GPR::B;
    if (str == "C") return GPR::C;
    if (str == "D") return GPR::D;
    if (str == "E") return GPR::E;
    if (str == "H") return GPR::H;
    if (str == "L") return GPR::L;
    if (str == "ACC") return SPR::ACC;
    if (str == "INSTRUCTION") return SPR::INSTRUCTION;
    throw std::invalid_argument("Invalid input: " + str);
}
