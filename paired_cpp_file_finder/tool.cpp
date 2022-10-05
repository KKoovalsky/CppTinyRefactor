/**
 * @file	tool.cpp
 * @brief	Entry point for the paired C++ file finder tool.
 */
#include <iostream>

#include "cmd_parser.hpp"

using namespace Tsepepe::PairedCppFileFinder;

int main(int argc, const char* argv[])
{
    auto input_or_return_code{parse_cmd(argc, argv)};
    if (std::holds_alternative<ReturnCode>(input_or_return_code))
        return std::get<ReturnCode>(input_or_return_code);

    auto input{std::get<Input>(input_or_return_code)};
    std::cout << "Root: " << input.project_directory << std::endl;
    std::cout << "C++ file: " << input.cpp_file << std::endl;
    return 0;
}
