#pragma once

#include <string>
#include <vector>

bool is_separator(char current_char);
bool is_keyword(std::string keyword);
bool is_alpha(std::string keyword);
bool is_float(std::string keyword);
bool is_bool(std::string keyword);