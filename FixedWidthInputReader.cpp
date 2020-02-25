//
// Created by laure on 25/02/2020.
//

#include "FixedWidthInputReader.hpp"

bool FixedWidthInputReader::ProcessChar(const char in_char) {
    if (in_char == '\n') {
        current_field_count_ = 0;
        current_field_chars_ = 0;
        return true;
    }
    current_field_ += in_char;
    ++current_field_chars_;
    if (field_widths_.at(current_field_count_) == current_field_chars_) {
        ++current_field_count_;
        current_field_chars_ = 0;
        return true;
    }
    return false;
}
