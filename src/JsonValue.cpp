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
    return std::get<JsonObject>(value);
}

json::JsonArray json::JsonValue::GetArray() {
    return std::get<JsonArray>(value);
}

json::JsonNumber json::JsonValue::GetNumber() {
    return std::get<JsonNumber>(value);
}

json::JsonString json::JsonValue::GetString() {
    return std::get<JsonString>(value);
}

json::JsonBoolean json::JsonValue::GetBoolean() {
    return std::get<JsonBoolean>(value);
}
