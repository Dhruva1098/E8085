// Copyright 2024 Dhruva Sharma

#include "headers/instruction_map.h"

#include <iostream>

#include "headers/instruction_set.hpp"

uint16_t string_to_hex(const std::string& str) {
    uint16_t hex_format;
    std::stringstream ss;
    ss << str;
    ss >> std::hex >> hex_format;
    return hex_format;
}

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
                uint16_t mem_location = string_to_hex(args[0]);
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
    // LHLD
    instruction_map["LHLD"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint16_t mem_location = (uint16_t)string_to_enum(args[0]);
                LHLD(mem_location);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() <<std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // STA
    instruction_map["STA"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint16_t mem_location = string_to_hex(args[0]);
                STA(mem_location);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() <<std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // STAX
    instruction_map["STAX"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                STAX(reg_name);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // PUSH
    instruction_map["PUSH"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                PUSH(reg_name);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // POP
    instruction_map["POP"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                POP(reg_name);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // ADD
    // check for is it ADD_R or ADD_M, write necessary functions for both
    // ADI
    instruction_map["ADI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)string_to_hex(args[0]);
                ADI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // ACI
    instruction_map["ACI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)string_to_hex(args[0]);
                ACI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given" << std:: endl;
        }
    };
    // AMC
    instruction_map["AMC"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t mem_location = (uint8_t)string_to_enum(args[0]);
                AMC(mem_location);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given" << std:: endl;
        }
    };
    // SUB
    // write conditions for SUB_R or SUB_M, write required code
    // SUI
    instruction_map["SUI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)string_to_hex(args[0]);
                SUI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << " ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: Function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // SBI
    instruction_map["SBI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)string_to_hex(args[0]);
                SBI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    return instruction_map;
}
