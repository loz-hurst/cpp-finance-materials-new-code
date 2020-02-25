#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "CSVInputReader.hpp"
#include "FixedWidthInputReader.hpp"

int main() {
    const std::string filename {"../test.dat"};
    std::shared_ptr<std::ifstream> in_file {std::make_shared<std::ifstream>(filename)};
    if (!in_file->good()){
        std::cerr << "Problem opening the file: " << filename << std::endl;
        return 1;
    }
    FixedWidthInputReader reader {in_file};

    std::cout << (*reader.GetNextField()) << std::endl;
    std::cout << (*reader.GetNextField()) << std::endl;
    std::cout << (*reader.GetNextField()) << std::endl;
    std::cout << (*reader.GetNextField()) << std::endl;
    std::cout << (*reader.GetNextField()) << std::endl;

    return 0;
}