// Copyright 2024 Dhruva Sharma

#include "headers/instruction_map.h"
#include "headers/instruction_set.hpp"

#include <iostream>

const std::map<std::string, std::function<void(const std::vector<std::string>&)>>& create_instruction_map() {
    static std::map<std::string, std::function<void(const std::vector<std::string>&)>> instruction_map;
    // Functions with 0 arguments
    instruction_map["SPHL"] = [](const std::vector<std::string>& args) {
        if (args.empty()) {
            SPHL();
        } else {
            std::cerr << "ERROR: function expects no arguments" << std::endl;
        }
    };
    return instruction_map;
}
