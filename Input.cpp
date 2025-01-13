/**
 * @file Input.cpp
 * @brief Реализация методов класса Input для управления текстом, разделителями и символом-заменителем.
 */

#include <Input.h>

void Input::SetText(const std::string& text) {
    this->text = text;
}

std::string Input::GetTextAsString() const {
    return text;
}

void Input::SetDelimiters(const std::vector<char>& delimiters) {
    this->delimiters = delimiters;
}

const std::vector<char>& Input::GetDelimiters() const {
    return delimiters;
}

void Input::SetReplacement(char replacement) {
    this->replacement = replacement;
}

char Input::GetReplacement() const {
    return replacement;
}

bool Input::HasText() const {
    return !text.empty();
}

bool Input::HasReplacement() const {
    return replacement != '\0';
}
