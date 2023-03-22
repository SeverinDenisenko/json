//
// Created by Severin on 22.03.2023.
//

#include "json/Tokenizer.hpp"

namespace json {
    Tokenizer::Tokenizer(const std::string& filename) {
        stream.open(filename);

        if (!stream)
            throw std::runtime_error("Can't open file!");
    }

    Token Tokenizer::GetToken() {
        if (stream.eof())
            throw std::runtime_error("No more tokens!");

        char c = ' ';
        while (c == ' ' || c == '\n'){
            stream.get(c);
        }

        Token token;

        switch (c) {
            case '{':
                token.type = Token::CURLY_OPEN;
                break;
            case '}':
                token.type = Token::CURLY_CLOSE;
                break;
            case '[':
                token.type = Token::SQUARE_OPEN;
                break;
            case ']':
                token.type = Token::SQUARE_CLOSE;
                break;
            case ',':
                token.type = Token::COMMA;
                break;
            case ';':
                token.type = Token::COLON;
                break;
            case '"':
                token.type = Token::STRING;

                c = getCharacter();
                while (c != '"') {
                    token.value += c;
                    c = getCharacter();
                }
                break;
            case 'n':
                token.type = Token::NULL_TYPE;

                token.value += 'n';
                expectCharacter('u');
                token.value += 'u';
                expectCharacter('l');
                token.value += 'l';
                expectCharacter('l');
                token.value += 'l';
                break;
            case 't':
                token.type = Token::BOOLEAN;

                token.value += 't';
                expectCharacter('r');
                token.value += 'r';
                expectCharacter('u');
                token.value += 'u';
                expectCharacter('e');
                token.value += 'e';
                break;
            case 'f':
                token.type = Token::BOOLEAN;

                token.value += 'f';
                expectCharacter('a');
                token.value += 'a';
                expectCharacter('l');
                token.value += 'l';
                expectCharacter('s');
                token.value += 's';
                expectCharacter('e');
                token.value += 'e';
                break;
            default:
                if (c != '-' && (c <= '0' || c >= '9'))
                    throw std::runtime_error("Cannot create token!");

                token.type = Token::NUMBER;

                while (true)
                {
                    auto prevPosition = stream.tellg();
                    c = getCharacter();

                    if (c == '-' || (c >= '0' && c <= '9') || c == '.'){
                        token.value += c;
                    } else {
                        stream.seekg(prevPosition);
                        break;
                    }
                }
                break;
        }

        return std::move(token);
    }

    bool Tokenizer::TokensEnded() {
        return stream.eof();
    }

    char Tokenizer::getCharacter() {
        char c;

        if (stream.eof())
            throw std::runtime_error("Unexpected end of file!");
        stream.get(c);

        return c;
    }

    void Tokenizer::expectCharacter(char e) {
        char c = getCharacter();
        if (c != e)
            throw std::runtime_error("Unexpected character!");
    }

    Token Tokenizer::GetCurrentToken() {
        std::streamoff position = stream.tellg();
        Token token = GetToken();
        stream.seekg(position);

        return std::move(token);
    }
} // json