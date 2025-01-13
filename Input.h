/**
 * @file Input.h
 * @brief Объявление класса Input для работы с текстом, разделителями и символом-заменителем.
 */

#pragma once

#include <string>
#include <vector>

/**
 * @brief Класс Input предоставляет методы для управления текстом, разделителями и символом-заменителем.
 */
class Input {
public:
    void SetText(const std::string& text);
    std::string GetTextAsString() const;

    void SetDelimiters(const std::vector<char>& delimiters);
    const std::vector<char>& GetDelimiters() const;

    void SetReplacement(char replacement);
    char GetReplacement() const;

    bool HasText() const;
    bool HasReplacement() const;

private:
    std::string text;
    std::vector<char> delimiters;
    char replacement = '\0';
};
