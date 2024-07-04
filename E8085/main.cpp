// Copyright 2024 Dhruva Sharma
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "headers/flag.h"
#include "headers/instruction_set.hpp"
#include "headers/parser.h"
uint16_t string_to_hex(const std::string& str) {
    uint16_t hex_format;
    std::stringstream ss;
    ss << str;
    ss >> std::hex >> hex_format;
    return hex_format;
}
int main() {
    std::string hex_stream = "0x0010";
    std::cout << (unsigned)string_to_hex(hex_stream);
}
