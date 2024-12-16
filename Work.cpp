/**
 * @file Work.cpp
 * @brief Реализация методов обработки текста.
 */

#include <Work.h>

bool Work::isDelimiter(char c, const std::string& delimiters) {
    return delimiters.find(c) != std::string::npos;
}

void Work::processText(std::string& str, char replacement, const std::string& delimiters) {
    for (char& c : str) {
        if (isDelimiter(c, delimiters)) {
            c = replacement;
        }
    }
}

void Work::processText(Input& input) {
    for (std::string& line : input.getText()) {
        processText(line, input.getReplacement(), input.getDelimiters());
    }
}
