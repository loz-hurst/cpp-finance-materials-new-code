//
// Created by laure on 11/02/2020.
//

#ifndef INPUTREADER_TSVINPUTREADER_HPP
#define INPUTREADER_TSVINPUTREADER_HPP

#include "InputReader.hpp"

class TSVInputReader : public InputReader {
protected:
    virtual bool ProcessChar(const char in_char) override;
};


#endif //INPUTREADER_TSVINPUTREADER_HPP
