//
// Created by Severin on 23.03.2023.
//

#include <utility>
#include <fstream>

#include "json/Writer.hpp"

namespace json {
    Writer::Writer(std::string filename) : filename(std::move(filename)) {

    }

    void Writer::Write(JsonValue& root) {
        stream.open(filename);

        writeToStream(root);

        stream.close();
    }

    void Writer::writeToStream(JsonValue& value) {
        switch (value.GetType()) {
            case JsonValue::ValueType::OBJECT:
                stream << "{";
                for (auto i = value.GetObject().begin(); i != value.GetObject().end();) {
                    stream << '"' << i->first << '"' << ": ";
                    writeToStream(i->second);
                    ++i;
                    if (i != value.GetObject().end())
                        stream << ", ";
                }
                stream << "}";
                break;
            case JsonValue::ValueType::ARRAY:
                stream << "[";
                for (auto i = value.GetArray().begin(); i != value.GetArray().end();) {
                    writeToStream(*i);
                    ++i;
                    if (i != value.GetArray().end())
                        stream << ", ";
                }
                stream << "]";
                break;
            case JsonValue::ValueType::NUMBER:
                stream << value.GetNumber();
                break;
            case JsonValue::ValueType::STRING:
                stream << '"' << value.GetString() << '"';
                break;
            case JsonValue::ValueType::BOOLEAN:
                if (value.GetBoolean())
                    stream << "true";
                else
                    stream << "false";
                break;
            case JsonValue::ValueType::NULL_TYPE:
                stream << "null";
                break;
        }
    }
} // json