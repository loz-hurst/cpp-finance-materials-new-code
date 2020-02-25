//
// Created by laure on 25/02/2020.
//

#ifndef INPUTREADER_FIXEDWIDTHINPUTREADER_HPP
#define INPUTREADER_FIXEDWIDTHINPUTREADER_HPP

#include "InputReader.hpp"

#include <array>

class FixedWidthInputReader : public InputReader {
private:
    const std::array<size_t, 3> field_widths_ {8, 3, 8};
    size_t current_field_count_;
    size_t current_field_chars_;
protected:
    virtual bool ProcessChar(const char) override;
public:
    FixedWidthInputReader(std::shared_ptr<std::istream> input_stream) : InputReader(input_stream), current_field_count_{0}, current_field_chars_{0} {}
};


#endif //INPUTREADER_FIXEDWIDTHINPUTREADER_HPP
