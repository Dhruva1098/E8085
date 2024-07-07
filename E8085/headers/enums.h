// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_ENUMS_H_
#define E8085_HEADERS_ENUMS_H_

#include <string>
#include<stdexcept>

enum {
    B = 0,
    C,
    D,
    E,
    H,
    L
};

enum {
    ACC = 0,
    INSTRUCTION
};

inline int string_to_enum(const std::string& str) {
    if (str == "B") return B;
    if (str == "C") return C;
    if (str == "D") return D;
    if (str == "E") return E;
    if (str == "H") return H;
    if (str == "L") return L;
    if (str == "ACC") return ACC;
    if (str == "INSTRUCTION") return INSTRUCTION;
    throw std::invalid_argument("Invalid input: " + str);
}
#endif  // E8085_HEADERS_ENUMS_H_
