/**
 * @file Out.cpp
 * @brief Реализация методов для вывода текста.
 */

#include <Out.h>
#include <iostream>
#include <fstream>

void Out::Show(const Input& input) const {
    std::cout << "Text: " << input.GetTextAsString() << std::endl;
}

void Out::SaveToFile(const Input& input, const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << input.GetTextAsString();
        file.close();
        std::cout << "Text saved to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}
