//
// Created by Severin on 22.03.2023.
//

#include <iostream>
#include "json/Parser.hpp"
#include "json/Writer.hpp"

int main(){
    json::Parser parser("tests/test.json");
    parser.Parse();

    parser.root["test3"] = false;
    parser.root["test4"] = 321.0;
    parser.root["test5"][0] = 3.0;
    parser.root["test5"][1] = 2.0;
    parser.root["test5"][2] = 1.0;
    parser.root["test6"]["test1"] = json::JsonArray();
    parser.root["test6"]["test2"] = json::JsonObject();

    json::Writer writer("tests/out.json");
    writer.Write(parser.root);

    return 0;
}
