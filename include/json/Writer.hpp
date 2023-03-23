//
// Created by Severin on 23.03.2023.
//

#ifndef JSON_WRITER_HPP
#define JSON_WRITER_HPP

#include <string>

#include "json/JsonValue.hpp"

namespace json {

    class Writer {
    public:
        explicit Writer(std::string filename);

        void Write(JsonValue& root);

    private:
        std::string filename;
        std::ofstream stream;

        void writeToStream(JsonValue& root);
    };

} // json

#endif //JSON_WRITER_HPP
