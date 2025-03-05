#include <Work.h>
#include <algorithm>

/**
 * @file Work.cpp
 * @brief Реализация методов класса Work для обработки текста.
 */

void Work::ProcessText(Input &input) {
  std::string processedText;
  for (char c : input.GetText()) {
    if (std::find(input.GetDelimiters().begin(), input.GetDelimiters().end(), c) != input.GetDelimiters().end()) {
      processedText += input.GetReplacement();
    } else {
      processedText += c;
    }
  }
  input.SetText(processedText);
}
