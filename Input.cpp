/**
 * @file Input.cpp
 * @brief Реализация методов класса Input.
 */

#include <Input.h>

void Input::SetText(const std::string& newText) {
    text = newText;
}

void Input::SetDelimiters(const std::vector<char>& newDelimiters) {
    delimiters = newDelimiters;
}

void Input::SetReplacement(char newReplacement) {
    replacement = newReplacement;
}

const std::string& Input::GetText() const {
    return text;
}

const std::vector<char>& Input::GetDelimiters() const {
    return delimiters;
}

char Input::GetReplacement() const {
    return replacement;
}
