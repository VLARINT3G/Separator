/**
 * @file Input.cpp
 * @brief Реализация методов ввода текста.
 */

#include <Input.h>
#include <iostream>
#include <sstream>

void Input::setDelimiters() {
    std::cout << "Enter delimiters: ";
    std::cin.ignore();
    std::getline(std::cin, delimiters_);
}

void Input::setText() {
    std::string buffer;
    std::cout << "Enter text lines (end with an empty line):\n";

    while (true) {
        std::getline(std::cin, buffer);
        if (buffer.empty()) break;
        text_.push_back(buffer);
    }
}

void Input::setReplacement() {
    std::cout << "Enter replacement character: ";
    std::cin >> replacement_;
}

bool Input::hasText() const {
    return !text_.empty();
}

bool Input::hasReplacement() const {
    return replacement_ != '\0';
}

std::string Input::getTextAsString() const {
    std::ostringstream combinedText;
    for (const auto& line : text_) {
        combinedText << line << "\\n";
    }
    return combinedText.str();
}
