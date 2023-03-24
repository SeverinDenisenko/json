//
// Created by Severin on 22.03.2023.
//

#include "json/Parser.hpp"

namespace json {
    Parser::Parser(const std::string& filename) : tokenizer(filename) {

    }

    void Parser::Parse() {
        root = parseToken();

        if (!tokenizer.TokensEnded())
            throw std::runtime_error("Bad json structure!");
    }

    void Parser::parseNull() {
        tokenizer.GetToken();
    }

    JsonBoolean Parser::parseBoolean() {
        Token token = tokenizer.GetToken();

        if (token.value == "true")
            return std::move(JsonBoolean(true));
        else if (token.value == "false")
            return std::move(JsonBoolean(false));

        throw std::runtime_error("Wtf?");
    }

    JsonString Parser::parseString() {
        Token token = tokenizer.GetToken();

        return std::move(JsonString(token.value));
    }

    JsonNumber Parser::parseNumber() {
        Token token = tokenizer.GetToken();

        return std::move(JsonNumber(std::stod(token.value)));
    }

    JsonArray Parser::parseArray() {
        auto array = JsonArray();

        Token token = tokenizer.GetToken();
        if (token.type != Token::SQUARE_OPEN)
            throw std::runtime_error("Invalid array beginning!");

        while (true){
            token = tokenizer.GetCurrentToken();
            if (token.type == Token::SQUARE_CLOSE){
                tokenizer.GetToken();
                break;
            }

            array.push_back(std::move(parseToken()));

            token = tokenizer.GetToken();
            if (token.type == Token::SQUARE_CLOSE)
                break;
            else if (token.type == Token::COMMA)
                continue;
            else
                throw std::runtime_error("Invalid token sequence in array!");
        }

        return std::move(array);
    }

    JsonObject Parser::parseObject() {
        auto object = JsonObject();

        Token token = tokenizer.GetToken();
        if (token.type != Token::CURLY_OPEN)
            throw std::runtime_error("Invalid object beginning!");

        while (true){
            auto key = tokenizer.GetToken();
            if (key.type == Token::CURLY_CLOSE)
                break;
            if (key.type != Token::TokenType::STRING)
                throw std::runtime_error("Invalid token sequence in object!");

            auto colon = tokenizer.GetToken();
            if (colon.type != Token::TokenType::COLON)
                throw std::runtime_error("Invalid token sequence in object!");

            object[key.value] = parseToken();
            token = tokenizer.GetToken();

            if (token.type == Token::CURLY_CLOSE)
                break;
            else if (token.type == Token::COMMA)
                continue;
            else
                throw std::runtime_error("Invalid token sequence in object!");
        }

        return std::move(object);
    }

    JsonValue Parser::parseToken() {
        Token token = tokenizer.GetCurrentToken();
        JsonValue value;

        switch (token.type) {
            case Token::CURLY_OPEN:
                value.Set(std::move(parseObject()));
                break;
            case Token::SQUARE_OPEN:
                value.Set(std::move(parseArray()));
                break;
            case Token::STRING:
                value.Set(std::move(parseString()));
                break;
            case Token::BOOLEAN:
                value.Set(std::move(parseBoolean()));
                break;
            case Token::NUMBER:
                value.Set(std::move(parseNumber()));
                break;
            case Token::NULL_TYPE:
                parseNull();
                break;
            default:
                throw std::runtime_error("Invalid sequence of tokens!");
        }

        return value;
    }
} // json