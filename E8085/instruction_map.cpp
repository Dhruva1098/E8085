// Copyright 2024 Dhruva Sharma

#include "headers/instruction_map.h"

#include <iostream>

#include "headers/instruction_set.hpp"
#include "headers/enums.h"


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
    // LDA
    instruction_map["LDA"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint16_t mem_location = (uint16_t)string_to_enum(args[0]);
                LDA(mem_location);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // LDAX
    instruction_map["LDAX"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                LDAX(reg_name);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    //LHLD
        return instruction_map;
}
