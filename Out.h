/**
 * @file Out.h
 * @brief Заголовочный файл для вывода текста.
 */

#pragma once

#include <string>
#include <Input.h>

class Out {
public:
    void show(const Input& input) const;
    void saveToFile(const Input& input, const std::string& filename) const;
};
