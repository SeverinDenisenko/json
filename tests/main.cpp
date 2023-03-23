//
// Created by Severin on 22.03.2023.
//

#include <iostream>
#include "json/Parser.hpp"

int main(){
    json::Parser parser("tests/test.json");
    parser.Parse();

    std::cout << parser.root.GetObject()["web-app"].GetObject()["servlet"].GetArray()[0].GetObject()["servlet-class"].GetString() << std::endl;

    return 0;
}
