#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "CSVInputReader.hpp"

int main() {
    const std::string filename {"../test.csv"};
    std::shared_ptr<std::ifstream> in_file {std::make_shared<std::ifstream>(filename)};
    if (!in_file->good()){
        std::cerr << "Problem opening the file: " << filename << std::endl;
        return 1;
    }
    CSVInputReader csv_reader {in_file};

    std::cout << (*csv_reader.GetNextField()) << std::endl;
    std::cout << (*csv_reader.GetNextField()) << std::endl;
    std::cout << (*csv_reader.GetNextField()) << std::endl;
    std::cout << (*csv_reader.GetNextField()) << std::endl;
    std::cout << (*csv_reader.GetNextField()) << std::endl;

    return 0;
}