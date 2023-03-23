//
// Created by Severin on 22.03.2023.
//

#include <iostream>
#include "json/Parser.hpp"
#include "json/Writer.hpp"

int main(){
    json::Parser parser("tests/test.json");
    parser.Parse();
    json::Writer writer("tests/out.json");
    writer.Write(parser.root);

    return 0;
}
