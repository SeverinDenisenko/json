//
// Created by Severin on 22.03.2023.
//

#include "json/Parser.hpp"
#include "json/Writer.hpp"
#include "json/Json.h"

int main(){
    json::Parser parser("tests/test.json");
    json::Json json = parser.Parse();

    json["test3"] = false;
    json["test4"] = 321.0;
    json["test5"][0] = 3.0;
    json["test5"][1] = 2.0;
    json["test5"][2] = 1.0;
    json["test6"]["test1"] = json::JsonArray();
    json["test6"]["test2"] = json::JsonObject();

    json::Writer writer("tests/out.json");
    writer.Write(json);

    return 0;
}
