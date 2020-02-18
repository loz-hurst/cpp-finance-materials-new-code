//
// Created by laure on 11/02/2020.
//

#ifndef INPUTREADER_TSVINPUTREADER_HPP
#define INPUTREADER_TSVINPUTREADER_HPP

#include <istream>
#include <memory>

#include "InputReader.hpp"

class TSVInputReader : public InputReader {
protected:
    virtual bool ProcessChar(const char in_char) override;
public:
    TSVInputReader(std::shared_ptr<std::istream> input_stream) : InputReader(input_stream) {}
};


#endif //INPUTREADER_TSVINPUTREADER_HPP
