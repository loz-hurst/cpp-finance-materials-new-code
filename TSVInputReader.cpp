//
// Created by laure on 11/02/2020.
//

#include "TSVInputReader.hpp"
#include <iostream>


bool TSVInputReader::ProcessChar(const char in_char) {
    //std::cout << "ProcessChar called with character '" << in_char << "'" << std::endl;
    if (in_char == '\t' || in_char == '\n')
        return true;

    current_field_ += in_char;
    return false;
}