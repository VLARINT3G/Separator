#pragma once
#include <Input.h>
#include <string>

/**
 * @file Out.h
 * @brief Класс для вывода текста на экран и сохранения его в файл.
 */



class Out {
public:
    void Show(const Input& input) const;
    void SaveToFile(const Input& input, const std::string& filePath) const;
};
