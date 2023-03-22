//
// Created by Severin on 22.03.2023.
//

#include "json/Parser.hpp"

namespace json {
    Parser::Parser(const std::string& filename) : tokenizer(filename) {

    }

    void Parser::Parse() {
        while (!tokenizer.TokensEnded()) {
            Token token = tokenizer.GetCurrentToken();
            JsonValue value;

            switch (token.type) {
                case Token::CURLY_OPEN:
                    value.Set(std::move(parseObject()));
                    break;
                case Token::STRING:
                    value.Set(std::move(parseString()));
                    break;
                case Token::SQUARE_OPEN:
                    value.Set(std::move(parseArray()));
                    break;
                case Token::BOOLEAN:
                    value.Set(std::move(parseBoolean()));
                    break;
                case Token::NULL_TYPE:
                    ParseNull();
                    break;
                case Token::NUMBER:
                    value.Set(std::move(parseNumber()));
                default:
                    throw std::runtime_error("Invalid sequence of tokens!");
            }
        }
    }

    void Parser::ParseNull() {
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
        //TODO

        return std::move(array);
    }

    JsonObject Parser::parseObject() {
        auto object = JsonObject();

        Token token = tokenizer.GetToken();
        //TODO

        return std::move(object);
    }
} // json