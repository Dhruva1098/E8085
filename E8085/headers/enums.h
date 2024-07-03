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

int string_to_enum(const std::string& str);
#endif  // E8085_HEADERS_ENUMS_H_
