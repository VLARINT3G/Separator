#include <Input.h>
#include <Work.h>
#include <Database.h>

#include <iostream>
#include <memory>

/**
 * @file main.cpp
 * @brief Основной файл программы, отвечающий за запуск и взаимодействие между компонентами.
 */

int main() {
    try {
        auto database = std::make_shared<Database>("text_processing.db");
        database->AddTable("CREATE TABLE IF NOT EXISTS TextEntries (id INTEGER PRIMARY KEY, text TEXT);");

        Input input;
        Work processor;

        char choice;
        do {
            std::cout << "\nМеню:\n"
                      << "1) Ввести текст\n"
                      << "2) Обработать текст\n"
                      << "3) Ввести разделители и символ замены\n"
                      << "4) Показать текст\n"
                      << "5) Выйти\n"
                      << "Выберите пункт: ";
            std::cin >> choice;

            switch (choice) {
                case '1': {
                    std::cout << "Введите текст: ";
                    std::cin.ignore();
                    std::string text;
                    std::getline(std::cin, text);
                    input.SetText(text);
                    break;
                }
                case '2': {
                    processor.ProcessText(input);
                    std::cout << "Текст обработан." << std::endl;
                    break;
                }
                case '3': {
                    std::cout << "Введите разделители (без пробелов): ";
                    std::string delimitersInput;
                    std::cin >> delimitersInput;
                    input.SetDelimiters(std::vector<char>(delimitersInput.begin(), delimitersInput.end()));

                    std::cout << "Введите символ замены: ";
                    char replacement;
                    std::cin >> replacement;
                    input.SetReplacement(replacement);
                    break;
                }
                case '4': {
                    std::cout << "Текущий текст: " << input.GetText() << std::endl;
                    break;
                }
                case '5': {
                    std::cout << "Выход." << std::endl;
                    break;
                }
                default:
                    std::cout << "Некорректный ввод. Попробуйте снова." << std::endl;
            }
        } while (choice != '5');
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
