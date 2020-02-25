//
// Created by laure on 25/02/2020.
//

#ifndef INPUTREADER_CSVINPUTREADER_HPP
#define INPUTREADER_CSVINPUTREADER_HPP

#include "InputReader.hpp"

class CSVInputReader : public InputReader {
private:
    bool inside_double_quote_;
    bool last_char_double_quote_;
protected:
    virtual bool ProcessChar(const char in_char);
public:
    CSVInputReader(std::shared_ptr<std::istream> input_stream) : InputReader(input_stream), inside_double_quote_{false}, last_char_double_quote_{false} {}
};


#endif //INPUTREADER_CSVINPUTREADER_HPP
