// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_PARSER_H_
#define E8085_HEADERS_PARSER_H_

#include <functional>
#include <string>
#include <map>
#include <vector>

void parse_and_execute(
                       const std::string& input, std::map<std::string,
                       std::function<void(const std::vector<std::string>&)>>& instruction_map);

#endif  // E8085_HEADERS_PARSER_H_
