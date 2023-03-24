//
// Created by Severin on 24.03.2023.
//

#ifndef JSON_EXCEPTION_HPP
#define JSON_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace json {

    class Exception : public std::exception {
    public:
        explicit Exception(const char* msg);

        const char* what() const noexcept override;

        const char* msg;
    };

} // json

#endif //JSON_EXCEPTION_HPP
