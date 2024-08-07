// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_INSTRUCTION_MAP_H_
#define E8085_HEADERS_INSTRUCTION_MAP_H_

#include <functional>
#include <vector>
#include <string>
#include <map>
#include <sstream>


const std::map<std::string, std::function<void(const std::vector<std::string>&)>>& create_instruction_map();

#endif  // E8085_HEADERS_INSTRUCTION_MAP_H_
