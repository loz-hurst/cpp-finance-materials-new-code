//
// Created by laure on 11/02/2020.
//

#ifndef INPUTREADER_INPUTREADER_HPP
#define INPUTREADER_INPUTREADER_HPP

#include <istream>
#include <memory>
#include <string>

class InputReader {
private:
    std::shared_ptr<std::istream> input_stream_;
protected:
    // Process next character from file.  Passed char as an argument.  Returns true if reached end of the current field.  False otherwise.
    virtual bool ProcessChar(const char) = 0;
    std::string current_field_;
public:
    InputReader(std::shared_ptr<std::istream> input_stream) : input_stream_{input_stream}, current_field_ {""} {}
    virtual std::unique_ptr<std::string> GetNextField();
};


#endif //INPUTREADER_INPUTREADER_HPP
