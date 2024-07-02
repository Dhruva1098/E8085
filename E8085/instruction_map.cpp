// Copyright 2024 Dhruva Sharma

#include "headers/instruction_map.h"
#include "headers/instruction_set.hpp"

#include <iostream>

const std::map<std::string, std::function<void(const std::vector<std::string>&)>>& create_instruction_map() {
    static std::map<std::string, std::function<void(const std::vector<std::string>&)>> instruction_map;
// one word instructions
    // SPHL
    instruction_map["SPHL"] = [](const std::vector<std::string>& args) {
        if (args.empty()) {
            SPHL();
        } else {
            std::cerr << "ERROR: function expects no arguments" << std::endl;
        }
    };
    // PCHL
    instruction_map["PCHL"] = [](const std::vector<std::string>& args) {
        if (args.empty()) {
            PCHL();
        } else {
            std::cerr << "ERROR: function expects no arguments" << std::endl;
        }
    };
    // CMC
    instruction_map["CMC"] = [](const std::vector<std::string>& args) {
        if (args.empty()) {
            CMC();
        } else {
            std::cerr << "ERROR: function expects no arguments" << std::endl;
        }
    };
    // STC
    instruction_map["STC"] = [](const std::vector<std::string>& args) {
        if (args.empty()) {
            STC();
        } else {
            std::cerr << "ERROR: function expects no arguments" << std::endl;
        }
    };
// two word instructions
    instruction_map["LDA"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            uint16_t mem_location = (uint16_t)std::stoi(args[0]);
            LDA(mem_location);
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    return instruction_map;
}
