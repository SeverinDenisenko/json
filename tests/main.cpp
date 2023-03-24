//
// Created by Severin on 22.03.2023.
//

#include <iostream>
#include "json/Parser.hpp"
#include "json/Writer.hpp"

int main(){
    json::Parser parser("tests/test.json");
    parser.Parse();

    parser.root.GetObject()["test3"].Set(false);
    parser.root.GetObject()["test4"].Set(321.0);
    parser.root.GetObject()["test5"].GetArray()[0].Set(3.0);
    parser.root.GetObject()["test5"].GetArray()[1].Set(2.0);
    parser.root.GetObject()["test5"].GetArray()[2].Set(1.0);
    parser.root.GetObject()["test6"].GetObject()["test1"].Set(json::JsonArray());
    parser.root.GetObject()["test6"].GetObject()["test2"].Set(json::JsonObject());

    json::Writer writer("tests/out.json");
    writer.Write(parser.root);

    return 0;
}
