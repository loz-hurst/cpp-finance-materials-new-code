//
// Created by laure on 11/02/2020.
//

#include <memory>
#include <string>
#include <exception>
#include <istream>
#include "InputReader.hpp"

std::unique_ptr<std::string> InputReader::GetNextField() {
    bool finished {false};

    while(!finished) {
        if (!input_stream_->good())
            throw std::runtime_error {"Problem with input stream in GetNextField"};
        char in_char{'\0'};
        input_stream_->get(in_char);
        if (input_stream_->eof())
            finished = true;
        else
            finished = ProcessChar(in_char);
    }

    std::unique_ptr<std::string> result {std::make_unique<std::string>(current_field_)};
    current_field_ = "";
    return result;
}