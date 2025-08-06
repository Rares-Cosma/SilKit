#include "../include/lexer.hpp"
#include "../include/types.hpp"

std::string open_file(const std::string& filename) {
    if (filename.empty()) {
        throw "Filename is empty. Construct the Lexer with a valid file.";
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw "Could not open file: " + filename;
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    return content;
}

void construct_from_separator(std::vector<Token>,char current_char,std::string content){
    
}

std::vector<Token> Lexer::tokenize() {
    // Lexing

    std::string content=open_file(filename);

    uint32_t index=0;
    uint32_t line_nb=0;
    std::string keyword;
    for (char current_char:content) {
        if (is_separator(current_char)){
            if (is_keyword(keyword)){
                Token tok;
                tok.value=keyword;
                tok.type="KEYWORD";
                tok.line="";
                tok.line_nb=0;
                keyword="";
            } else if (is_alpha(keyword)){

            } else if (is_float(keyword)) {

            }
            construct_from_separator(tokens,current_char,content);
        } else if (current_char == '\"' || current_char == '\''){

        } else {
            keyword+=current_char;
        }
        index++;
    }

    return {};
}