// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_ENUMS_H_
#define E8085_HEADERS_ENUMS_H_

#include <string>
#include<stdexcept>

enum GPR {
    B = 0,
    C,
    D,
    E,
    H,
    L
};

enum SPR {
    ACC = 0,
    INSTRUCTION
};

inline int string_to_enum(const std::string& str) {
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
#endif  // E8085_HEADERS_ENUMS_H_
