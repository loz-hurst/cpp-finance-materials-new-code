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
#include <string>
#include <memory>

#include "InputReader.hpp"
#include "FixedWidthInputReader.hpp" // For templated factory

// Program entry point
int main() {
    const std::string filename {"../test.dat"}; // Input filename

    // Create an instance of our FixedWidthInputReader
    //FixedWidthInputReader<8, 3, 8> reader {in_file};
    std::unique_ptr<InputReader> reader;

    try {
        // For CSV or TSV (uses file extension to choose)
        //reader = InputReaderFactory(filename);
        // For fixed width fields - field widths are template arguments
        reader = InputReaderFactory<8, 3, 8>(filename);
    } catch (const std::exception & e) {
        std::cerr << "A problem occurred opening " << filename << ": " << e.what() << std::endl;
        return 1; // Abort with error status
    }

    // Get the first 5 fields
    std::cout << reader->GetNextField() << std::endl;
    std::cout << reader->GetNextField() << std::endl;
    std::cout << reader->GetNextField() << std::endl;
    std::cout << reader->GetNextField() << std::endl;
    std::cout << reader->GetNextField() << std::endl;

    return 0;
}

