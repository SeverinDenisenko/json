//
// Created by Severin on 22.03.2023.
//

#include "json/Parser.hpp"
#include "json/Exception.hpp"

namespace json {
    Parser::Parser(const std::string& filename) : tokenizer(filename) {

    }

    JsonValue Parser::Parse() {
        root = parseToken();

        if (!tokenizer.TokensEnded())
            throw Exception("Bad json structure!");

        return root;
    }

    void Parser::parseNull() {
        tokenizer.GetToken();
    }

    JsonBoolean Parser::parseBoolean() {
        Token token = tokenizer.GetToken();

        if (token.value == "true")
            return JsonBoolean(true);
        else if (token.value == "false")
            return JsonBoolean(false);

        throw std::runtime_error("Wtf?");
    }

    JsonString Parser::parseString() {
        Token token = tokenizer.GetToken();

        return JsonString(token.value);
    }

    JsonNumber Parser::parseNumber() {
        Token token = tokenizer.GetToken();

        return JsonNumber(std::stod(token.value));
    }

    JsonArray Parser::parseArray() {
        auto array = JsonArray();

        Token token = tokenizer.GetToken();
        if (token.type != Token::SQUARE_OPEN)
            throw Exception("Invalid array beginning!");

        while (true){
            token = tokenizer.GetCurrentToken();
            if (token.type == Token::SQUARE_CLOSE){
                tokenizer.GetToken();
                break;
            }

            array.push_back(parseToken());

            token = tokenizer.GetToken();
            if (token.type == Token::SQUARE_CLOSE)
                break;
            else if (token.type == Token::COMMA)
                continue;
            else
                throw Exception("Invalid token sequence in array!");
        }

        return array;
    }

    JsonObject Parser::parseObject() {
        auto object = JsonObject();

        Token token = tokenizer.GetToken();
        if (token.type != Token::CURLY_OPEN)
            throw Exception("Invalid object beginning!");

        while (true){
            auto key = tokenizer.GetToken();
            if (key.type == Token::CURLY_CLOSE)
                break;
            if (key.type != Token::TokenType::STRING)
                throw Exception("Invalid token sequence in object!");

            auto colon = tokenizer.GetToken();
            if (colon.type != Token::TokenType::COLON)
                throw Exception("Invalid token sequence in object!");

            object[key.value] = parseToken();
            token = tokenizer.GetToken();

            if (token.type == Token::CURLY_CLOSE)
                break;
            else if (token.type == Token::COMMA)
                continue;
            else
                throw Exception("Invalid token sequence in object!");
        }

        return object;
    }

    JsonValue Parser::parseToken() {
        Token token = tokenizer.GetCurrentToken();
        JsonValue value;

        switch (token.type) {
            case Token::CURLY_OPEN:
                value.Set(parseObject());
                break;
            case Token::SQUARE_OPEN:
                value.Set(parseArray());
                break;
            case Token::STRING:
                value.Set(parseString());
                break;
            case Token::BOOLEAN:
                value.Set(parseBoolean());
                break;
            case Token::NUMBER:
                value.Set(parseNumber());
                break;
            case Token::NULL_TYPE:
                parseNull();
                break;
            default:
                throw Exception("Invalid sequence of tokens!");
        }

        return value;
    }
} // json