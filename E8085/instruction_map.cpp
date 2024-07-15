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
                    ADD_R(reg_name);
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
    // INX, DCR, DCX need to be defined first in instriction_set.cpp
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
    // CPI
    instruction_map["CPI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)std::stoi(args[0]);
                CPI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // ANA
    instruction_map["ANA"] = [](const std::vector<std::string>& args) {
        if (args.size() == 4) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    ANA_M(mem_location);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                    ANA_R(reg_name);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument "
            << "no or more arguments were given" << std::endl;
        }
    };
    // ANI
    instruction_map["ANI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)std::stoi(args[0]);
                ANI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // ORA
    instruction_map["ORA"] = [](const std::vector<std::string>& args) {
        if (args.size() == 4) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    ORA_M(mem_location);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                    ORA_R(reg_name);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument "
            << "no or more arguments were given" << std::endl;
        }
    };

    // ORI
    instruction_map["ORI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)std::stoi(args[0]);
                ORI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
    // XRA
    instruction_map["XRA"] = [](const std::vector<std::string>& args) {
        if (args.size() == 4) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    XRA_M(mem_location);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                    XRA_R(reg_name);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR: function expects exactly one argument "
            << "no or more arguments were given" << std::endl;
        }
    };

    // XRI
    instruction_map["XRI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 1) {
            try {
                uint8_t data = (uint8_t)std::stoi(args[0]);
                XRI(data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly one argument, "
            << "no or more arguments were given" << std::endl;
        }
    };
// TWO WORD INSTRUCTIONS
    // MOV
    instruction_map["MOV"] = [](const std::vector<std::string>& args) {
        if (args.size() == 2) {
            try {
                if (args[0].length() == 4) {
                    uint16_t mem_location = (uint16_t)string_to_hex(args[0]);
                    uint8_t data = (uint8_t)std::stoi(args[1]);
                    MOV_MD(mem_location, data);
                } else {
                    uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                    uint16_t mem_location = (uint16_t)string_to_hex(args[1]);
                    MOV_RM(reg_name, mem_location);
                }
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly two arguments, "
            << "less or more were given" << std::endl;
        }
    };
    // MVI
    instruction_map["MVI"] = [](const std::vector<std::string>& args) {
        if (args.size() == 2) {
            try {
                uint8_t reg_name = (uint8_t)string_to_enum(args[0]);
                uint8_t data = (uint8_t)std::stoi(args[1]);
                MVI(reg_name, data);
            } catch (const std::invalid_argument& ex) {
                std::cerr << "ERROR: " << ex.what() << std::endl;
            }
        } else {
            std::cerr << "ERROR function expects exactly two arguments, "
            << "less or more were given" << std::endl;
        }
    };
    return instruction_map;
}
