#pragma once
#include <string>
#include <vector>

/**
 * @file Input.h
 * @brief Класс для работы с вводом текста и настройкой параметров обработки.
 */



class Input {
public:
    void SetText(const std::string& text);
    void SetDelimiters(const std::vector<char>& delimiters);
    void SetReplacement(char replacement);

    const std::string& GetText() const;
    const std::vector<char>& GetDelimiters() const;
    char GetReplacement() const;

private:
    std::string text;
    std::vector<char> delimiters;
    char replacement;
};
