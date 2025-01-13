/**
 * @file Out.cpp
 * @brief Реализация методов класса Out.
 */

#include <Out.h>
#include <fstream>
#include <iostream>

void Out::Show(const Input& input) const {
    std::cout << "Text: " << input.GetText() << std::endl;
}

void Out::SaveToFile(const Input& input, const std::string& filePath) const {
    std::ofstream file(filePath);
    if (!file) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }
    file << input.GetText();
}
