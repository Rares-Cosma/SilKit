#include "../include/lexer.hpp"

void process(int argc, char *argv[]){
    switch (argc)
    {
        case 1:
            throw "Filename required to start the transpiler.";
        default:
            std::string filename="";
            bool spec_file=false;
            

            for (int i=1;i<argc;i++){
                std::string flag=argv[i];
                if (flag[0]=='-'){
                    // parse flags
                } else if (!spec_file) {
                    filename=flag;
                    spec_file=true;
                } else {
                    throw "Specified two or more keywords that aren't flags.";
                }
            }

            Lexer lexer(filename);
            std::vector<Token> tokens=lexer.tokenize();

            for (auto token:tokens){
                std::cout<<token.value<<" : "<<token.type<<std::endl;
            }

            break;
    }
}

int main(int argc, char *argv[]){
    try {
        process(argc, argv);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Unknown error occurred." << std::endl;
        return 1;
    }
    return 0;
}