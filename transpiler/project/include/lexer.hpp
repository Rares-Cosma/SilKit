#pragma once

#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

struct Token {
    int line_nb;
    std::string line;
    std::string type;
    std::string value;
};

class Lexer {
    public:
        std::string filename;
        std::vector<Token> tokens;
        Lexer(std::string fn) {
            filename=fn;
        }
        std::vector<Token> tokenize();
};