//
// Created by Severin on 24.03.2023.
//

#include <utility>

#include "json/Exception.hpp"

namespace json {
    Exception::Exception(const char* msg) : msg(msg){

    }

    const char* Exception::what() const noexcept {
        return msg;
    }
} // json