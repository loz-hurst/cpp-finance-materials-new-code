#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "TSVInputReader.hpp"

int main() {
    const std::string filename {"../test.tsv"};
    std::shared_ptr<std::ifstream> in_file {std::make_shared<std::ifstream>(filename)};
    if (!in_file->good()){
        std::cerr << "Problem opening the file: " << filename << std::endl;
        return 1;
    }
    TSVInputReader tsv_reader {in_file};

    std::cout << (*tsv_reader.GetNextField()) << std::endl;
    std::cout << (*tsv_reader.GetNextField()) << std::endl;
    std::cout << (*tsv_reader.GetNextField()) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}