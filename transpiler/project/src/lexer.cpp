#include "../include/lexer.hpp"
#include "../include/types.hpp"

std::vector<std::string> open_file(const std::string& filename) {
    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty. Construct the Lexer with a valid file.");
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

std::vector<Token> Lexer::tokenize() {
    // Lexing

    std::vector<Token> tokens;

    std::vector<std::string> content=open_file(filename);
    size_t line_number=1;
    std::string keyword="";

    for (std::string line:content) {
        keyword="";
        for (int pos=0;pos<line.size();pos++) {
            char current_char=line[pos];
            if (is_separator(current_char)){
                if (!keyword.empty()) {
                    Token tok;
                    tok.value = keyword;
                    tok.line = line;
                    tok.line_nb = line_number;

                    if (is_keyword(keyword)) tok.type = "KEYWORD";
                    else if (is_int(keyword)) tok.type = "INT";
                    else if (is_float(keyword)) tok.type = "FLOAT";
                    else if (is_bool(keyword)) tok.type = "BOOLEAN";
                    else tok.type = "IDENTIFIER";

                    tokens.push_back(tok);
                    keyword.clear();
                }
                if (!isspace(current_char)) {
                    Token sepTok;
                    sepTok.value = std::string(1, current_char);
                    sepTok.line = line;
                    sepTok.line_nb = line_number;
                    sepTok.type = "SEPARATOR";
                    tokens.push_back(sepTok);
                }
            } else if (current_char == '\"' || current_char == '\''){
                char quote = current_char;
                std::string str_value;
                pos++;
                while (pos < line.size() && line[pos] != quote) {
                    if (line[pos] == '\\' && pos + 1 < line.size()) {
                        str_value += line[pos];
                        pos++;
                    }
                    str_value += line[pos];
                    pos++;
                }

                Token strTok;
                strTok.value = str_value;
                strTok.line = line;
                strTok.line_nb = line_number;
                strTok.type = "STRING";
                tokens.push_back(strTok);
            } else {
                keyword+=current_char;
            }
        }

        line_number++;

        if (!keyword.empty()) {
            Token tok;
            tok.value = keyword;
            tok.line = line;
            tok.line_nb = line_number;

            if (is_keyword(keyword)) tok.type = "KEYWORD";
            else if (is_int(keyword)) tok.type = "INT";
            else if (is_float(keyword)) tok.type = "FLOAT";
            else if (is_bool(keyword)) tok.type = "BOOLEAN";
            else tok.type = "IDENTIFIER";

            tokens.push_back(tok);
        }
    }

    return tokens;
}