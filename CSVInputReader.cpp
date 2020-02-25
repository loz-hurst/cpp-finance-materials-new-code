//
// Created by laure on 25/02/2020.
//

#include "CSVInputReader.hpp"

bool CSVInputReader::ProcessChar(const char in_char) {
    switch(in_char) {
        case ',':
        case '\n':
            if (inside_double_quote_ && last_char_double_quote_) {
                inside_double_quote_ = false;
                last_char_double_quote_ = false;
            }
            if (inside_double_quote_) {
                current_field_ += in_char;
                break;
            } else {
                return true;
            }
        case '"':
            if(inside_double_quote_) {
                if (last_char_double_quote_) {
                    current_field_ += in_char;
                    last_char_double_quote_ = false;
                    break;
                } else {
                    last_char_double_quote_ = true;
                }
            } else {
                inside_double_quote_ = true;
            }
            break;
        default:
            current_field_ += in_char;
            if (last_char_double_quote_) {
                inside_double_quote_ = false;
                last_char_double_quote_ = false;
            }
    }
    return false;
}