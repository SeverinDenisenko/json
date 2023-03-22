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

        void Parse();

    private:
        JsonObject parseObject();
        JsonArray parseArray();
        JsonNumber parseNumber();
        JsonString parseString();
        JsonBoolean parseBoolean();
        void ParseNull();

        std::shared_ptr<JsonValue> root;
        Tokenizer tokenizer;
    };

} // json

#endif //JSON_PARSER_HPP
