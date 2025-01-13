/**
 * @file Out.h
 * @brief Заголовочный файл для вывода текста.
 */

#pragma once

#include <Input.h>

/**
 * @brief Класс для вывода текста.
 */
class Out {
public:
    void Show(const Input& input) const;
    void SaveToFile(const Input& input, const std::string& filename) const;
};
