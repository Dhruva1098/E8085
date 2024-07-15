// Copyright 2024 Dhruva Sharma

#include "headers/instruction_map.h"

#include <iostream>

#include "headers/instruction_set.hpp"


const std::map<std::string, std::function<void(const std::vector<std::string>&)>>& create_instruction_map() {
    static std::map<std::string, std::function<void(const std::vector<std::string>&)>> instruction_map;
    // one word instructions
    // SPHL
    instruction_map["SPHL"] = [](const std::vector<std::string>& args){
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
                uint16_t mem_location = std::stoi(args[0]);
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
                uint16_t mem_location = std::stoi(args[0]);
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
    // ADD
    instruction_map["ADD"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    ADD_M(mem_location);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: functrion expects exactly one argument,"
            << " no or more arguments were given" << std::endl;
        }
    };
    // ADI
    instruction_map["ADI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)std::stoi(args[0]);
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
                uint8_t data = (uint8_t)std::stoi(args[0]);
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
    instruction_map["SUB"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    SUB_M(mem_location);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                    SUB_R(reg_name);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given " << std::endl;
        }
    };
    // SUI
    instruction_map["SUI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)std::stoi(args[0]);
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
                uint8_t data = (uint8_t)std::stoi(args[0]);
                SBI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // INX
    instruction_map["INX"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                INX(reg_name);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // DCX
    instruction_map["DCX"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                DCX(reg_name);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function exppects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // DCR
    instruction_map["DCR"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                DCR(mem_location);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // LOGICAL INSTRUCTONS
    // CMP
    instruction_map["CMP"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    CMP_M(mem_location);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                    CMP_R(reg_name);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERRIR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly one argument, "
            << "no or more argumenst were given" << std::endl;
        }
    };
    
    return instruction_map;
}
