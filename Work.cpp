/**
 * @file Work.cpp
 * @brief Реализация функциональности обработки текста.
 */

#include <Work.h>
#include <Input.h>
#include <algorithm> // Для std::find

void Work::ProcessText(Input& input) {
    std::string text = input.GetTextAsString();
    const auto& delimiters = input.GetDelimiters();

    for (char& c : text) {
        if (std::find(delimiters.begin(), delimiters.end(), c) != delimiters.end()) {
            c = input.GetReplacement();
        }
    }

    input.SetText(text);
}
