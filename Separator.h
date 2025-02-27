#pragma once

#include <string>

/**
 * @brief Класс Separator используется для добавления разделителя между элементами в строке.
 */
class Separator {
 public:
  /**
   * @brief Конструктор Separator.
   * @param subStr Разделитель, который будет использоваться.
   */
  explicit Separator(const std::string &subStr);

  /**
   * @brief Получает строку-разделитель. При первом вызове возвращает пустую строку.
   * @return Разделитель или пустая строка, если вызывается впервые.
   */
  std::string Get() const;

 private:
  std::string subStr_; ///< Строка-разделитель.
  mutable bool first_; ///< Флаг, указывающий, был ли уже вызван метод Get.
};
