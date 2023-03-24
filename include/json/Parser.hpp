//
// Created by Severin on 22.03.2023.
//

#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include <string>

#include "json/Tokenizer.hpp"
#include "json/JsonValue.hpp"

namespace json {

    class Parser {
    public:
        explicit Parser(const std::string& filename);

        JsonValue Parse();
    private:
        JsonValue root;
        Tokenizer tokenizer;

        JsonObject parseObject();
        JsonArray parseArray();
        JsonNumber parseNumber();
        JsonString parseString();
        JsonBoolean parseBoolean();
        void parseNull();

        JsonValue parseToken();
    };

} // json

#endif //JSON_PARSER_HPP
