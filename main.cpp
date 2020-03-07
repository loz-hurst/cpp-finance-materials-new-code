/*
 * Copyright 2020 Laurence Alexander Hurst
 *
 * This file is part of C++ for Finance.
 *
 * C++ for Finance is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * C++ for Finance is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with C++ for Finance.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "TSVInputReader.hpp"

// Program entry point
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

