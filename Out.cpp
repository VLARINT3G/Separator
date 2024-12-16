/**
 * @file Out.cpp
 * @brief Реализация методов вывода текста.
 */

#include <Out.h>
#include <iostream>
#include <fstream>

void Out::show(const Input& input) const {
    for (const auto& line : input.getText()) {
        std::cout << line << std::endl;
    }
}

void Out::saveToFile(const Input& input, const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& line : input.getText()) {
            file << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Failed to save text to file." << std::endl;
    }
}
