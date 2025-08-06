#include "../include/types.hpp"

bool is_separator(char current_char){
    std::string sep = " =;:+-*/(){}[],-<>!%|&\n\r\t";
    return sep.find(current_char) != std::string::npos;
}

bool is_keyword(std::string keyword){
    std::vector<std::string> keywords = {"dat","def","if","then","else","observe","assert","return","repeat","for","while","in","cobserve","import","Π","Pi","∏","cprod","as","coerce","pun","forget","typeof","_","wild","lambda","quantum","const","moved","lifted","qfree","mfree","classical","do","with","λ"};
    for (const std::string& kw : keywords) {
        if (keyword == kw) return true;
    }
    return false;
}

bool is_alpha(std::string keyword){}

bool is_float(std::string keyword){}

bool is_bool(std::string keyword){}