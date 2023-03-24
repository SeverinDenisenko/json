#include <utility>

#include "json/JsonValue.hpp"
#include "json/Exception.hpp"

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

const  json::JsonObject& json::JsonValue::GetObject() const{
    if (type != ValueType::OBJECT)
        throw Exception("Can't get object!");

    return std::get<JsonObject>(value);
}

const  json::JsonArray& json::JsonValue::GetArray() const{
    if (type != ValueType::ARRAY)
        throw Exception("Can't get array!");

    return std::get<JsonArray>(value);
}

const  json::JsonNumber& json::JsonValue::GetNumber() const{
    if (type != ValueType::NUMBER)
        throw Exception("Can't get number!");

    return std::get<JsonNumber>(value);
}

const  json::JsonString& json::JsonValue::GetString() const{
    if (type != ValueType::STRING)
        throw Exception("Can't get string!");

    return std::get<JsonString>(value);
}

const  json::JsonBoolean& json::JsonValue::GetBoolean() const{
    if (type != ValueType::BOOLEAN)
        throw Exception("Can't get boolean!");

    return std::get<JsonBoolean>(value);
}


json::JsonObject& json::JsonValue::GetObject(){
    if (type != ValueType::OBJECT)
        throw Exception("Can't get object!");

    return std::get<JsonObject>(value);
}

json::JsonArray& json::JsonValue::GetArray(){
    if (type != ValueType::ARRAY)
        throw Exception("Can't get array!");

    return std::get<JsonArray>(value);
}

json::JsonNumber& json::JsonValue::GetNumber(){
    if (type != ValueType::NUMBER)
        throw Exception("Can't get number!");

    return std::get<JsonNumber>(value);
}

json::JsonString& json::JsonValue::GetString(){
    if (type != ValueType::STRING)
        throw Exception("Can't get string!");

    return std::get<JsonString>(value);
}

json::JsonBoolean& json::JsonValue::GetBoolean(){
    if (type != ValueType::BOOLEAN)
        throw Exception("Can't get boolean!");

    return std::get<JsonBoolean>(value);
}

json::JsonValue& json::JsonValue::operator[](const std::string& string) {
    return GetObject()[string];
}


json::JsonValue& json::JsonValue::operator[](const std::size_t& index) {
    return GetArray()[index];
}

const json::JsonValue& json::JsonValue::operator[](const std::string& string) const{
    return GetObject().at(string);
}

const json::JsonValue& json::JsonValue::operator[](const std::size_t& index) const{
    return GetArray().at(index);
}

json::JsonValue& json::JsonValue::operator=(json::JsonNumber number) {
    Set(number);
    return *this;
}

json::JsonValue& json::JsonValue::operator=(json::JsonString string) {
    Set(string);
    return *this;
}

json::JsonValue& json::JsonValue::operator=(json::JsonBoolean boolean) {
    Set(boolean);
    return *this;
}

json::JsonValue& json::JsonValue::operator=(json::JsonObject object) {
    Set(object);
    return *this;
}

json::JsonValue& json::JsonValue::operator=(json::JsonArray array) {
    Set(array);
    return *this;
}
