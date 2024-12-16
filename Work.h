/**
 * @file Work.h
 * @brief Заголовочный файл для обработки текста.
 */

#pragma once

#include <string>
#include <Input.h>

class Work {
public:
    bool isDelimiter(char c, const std::string& delimiters);
    void processText(std::string& str, char replacement, const std::string& delimiters);
    void processText(Input& input);
};
