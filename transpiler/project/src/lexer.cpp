#include "../include/lexer.hpp"

std::vector<Token> Lexer::tokenize() {

    // Reading the file content

    if (filename==""){
        throw "\nConstruct class Lexer before tokenizing.\n";
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw "\nCould not open file.\n";
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    file.close();

    // Lexing

    return {};
}