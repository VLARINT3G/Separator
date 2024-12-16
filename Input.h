/**
 * @file Input.h
 * @brief Заголовочный файл для ввода текста.
 */

#pragma once

#include <vector>
#include <string>

class Input {
public:
    void setDelimiters();
    void setText();
    void setReplacement();
    bool hasText() const;
    bool hasReplacement() const;
    std::string getTextAsString() const; // Метод для объединения текста в строку
    std::vector<std::string>& getText() { return text_; }
    const std::vector<std::string>& getText() const { return text_; }
    const std::string& getDelimiters() const { return delimiters_; }
    char getReplacement() const { return replacement_; }

private:
    std::vector<std::string> text_;
    std::string delimiters_;
    char replacement_ = '\0';
};
