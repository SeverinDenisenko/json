//
// Created by Severin on 22.03.2023.
//

#ifndef JSON_TOKENIZER_HPP
#define JSON_TOKENIZER_HPP

#include <string>
#include <fstream>

namespace json {
    class Token {
    public:
        enum TokenType
        {
            CURLY_OPEN,
            CURLY_CLOSE,
            COLON,
            STRING,
            NUMBER,
            SQUARE_OPEN,
            SQUARE_CLOSE,
            COMMA,
            BOOLEAN,
            NULL_TYPE
        };

        TokenType type;
        std::string value;
    };

    class Tokenizer {
    public:
        explicit Tokenizer(const std::string& filename);

        Token GetToken();
        Token GetCurrentToken();
        bool TokensEnded();
    private:
        std::ifstream stream;

        char getCharacter();
        void expectCharacter(char c);
    };

} // json

#endif //JSON_TOKENIZER_HPP
