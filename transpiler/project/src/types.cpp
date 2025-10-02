#include "../include/types.hpp"

bool is_separator(char current_char){
    std::string sep = " =;:+-*/(){}[],-<>!%|&.\n\r\t";
    return sep.find(current_char) != std::string::npos;
}

bool is_keyword(const std::string& keyword){
    std::vector<std::string> keywords = {"dat","def","if","then","else","observe","assert","return","repeat","for","while","in","cobserve","import","Π","Pi","∏","cprod","as","coerce","pun","forget","typeof","_","wild","lambda","quantum","const","moved","lifted","qfree","mfree","classical","do","with","λ"};
    for (const std::string& kw : keywords) {
        if (keyword == kw) return true;
    }
    return false;
}

bool is_int(const std::string& s) {
    if (s.empty()) return false;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-') {
        i++;
        if (i == s.size()) return false;
    }

    for (; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }

    return true;
}

bool is_float(const std::string& s) {
    if (s.empty()) return false;
    size_t i = 0;
    bool has_dot = false, has_digit = false;

    if (s[i] == '+' || s[i] == '-') {
        i++;
        if (i == s.size()) return false;
    }

    for (; i < s.size(); i++) {
        if (isdigit(s[i])) {
            has_digit = true;
        } else if (s[i] == '.') {
            if (has_dot) return false;
            has_dot = true;
        } else {
            return false;
        }
    }

    return has_digit && has_dot;
}

bool is_bool(const std::string& keyword){
    return keyword == "true" || keyword == "false";
}