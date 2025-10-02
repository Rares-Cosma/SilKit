#pragma once

#include <string>
#include <vector>
#include <cctype>

bool is_separator(char current_char);
bool is_keyword(const std::string& keyword);
bool is_int(const std::string& keyword);
bool is_float(const std::string& keyword);
bool is_bool(const std::string& keyword);