#include "json/JsonValue.hpp"

json::JsonValue::JsonValue(json::JsonObject object) {
    type = ValueType::OBJECT;
    value = std::move(object);
}

json::JsonValue::JsonValue(json::JsonArray array) {
    type = ValueType::ARRAY;
    value = std::move(array);
}

json::JsonValue::JsonValue(json::JsonNumber number) {
    type = ValueType::NUMBER;
    value = std::move(number);
}

json::JsonValue::JsonValue(json::JsonString string) {
    type = ValueType::STRING;
    value = std::move(string);
}

json::JsonValue::JsonValue(json::JsonBoolean boolean) {
    type = ValueType::BOOLEAN;
    value = std::move(boolean);
}

void json::JsonValue::Set(json::JsonObject object) {
    type = ValueType::OBJECT;
    value = std::move(object);
}

void json::JsonValue::Set(json::JsonArray array) {
    type = ValueType::ARRAY;
    value = std::move(array);
}

void json::JsonValue::Set(json::JsonNumber number) {
    type = ValueType::NUMBER;
    value = std::move(number);
}

void json::JsonValue::Set(json::JsonString string) {
    type = ValueType::STRING;
    value = std::move(string);
}

void json::JsonValue::Set(json::JsonBoolean boolean) {
    type = ValueType::BOOLEAN;
    value = std::move(boolean);
}

json::JsonValue::JsonValue() {
    type = ValueType::NULL_TYPE;
}

json::JsonValue::ValueType json::JsonValue::GetType() {
    return type;
}

json::JsonObject json::JsonValue::GetObject() {
    if (type != ValueType::OBJECT)
        throw std::runtime_error("Can't get object!");

    return std::get<JsonObject>(value);
}

json::JsonArray json::JsonValue::GetArray() {
    if (type != ValueType::ARRAY)
        throw std::runtime_error("Can't get array!");

    return std::get<JsonArray>(value);
}

json::JsonNumber json::JsonValue::GetNumber() {
    if (type != ValueType::NUMBER)
        throw std::runtime_error("Can't get number!");

    return std::get<JsonNumber>(value);
}

json::JsonString json::JsonValue::GetString() {
    if (type != ValueType::STRING)
        throw std::runtime_error("Can't get string!");

    return std::get<JsonString>(value);
}

json::JsonBoolean json::JsonValue::GetBoolean() {
    if (type != ValueType::BOOLEAN)
        throw std::runtime_error("Can't get boolean!");

    return std::get<JsonBoolean>(value);
}
