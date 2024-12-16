/**
 * @file main.cpp
 * @brief Основной файл программы, отвечающий за запуск и взаимодействие между компонентами.
 */

#include <Input.h>
#include <Work.h>
#include <Out.h>
#include <Database.h>

#include <iostream>
#include <memory>

/**
 * @brief Точка входа в программу.
 * @return Код завершения программы (0 при успешном завершении).
 */
int main() {
    auto db = std::make_shared<Database>("text_processing.db");
    CreateTable table("TextEntries");
    table.addStringColumn("text");

    if (!db->addTable(table)) {
        std::cerr << "Failed to initialize database." << std::endl;
        return 1;
    }

    Input input;
    Work processor;
    Out output;

    char choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1) Enter text\n";
        std::cout << "2) Process text\n";
        std::cout << "3) Enter delimiters and replacement character\n";
        std::cout << "4) Show text\n";
        std::cout << "5) Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cin.ignore();
                input.setText();
                break;
            case '2':
                if (input.hasText() && input.hasReplacement()) {
                    processor.processText(input);
                    std::cout << "Text processed." << std::endl;
                } else {
                    std::cout << "Error: No text or replacement character provided." << std::endl;
                }
                break;
            case '3':
                input.setDelimiters();
                input.setReplacement();
                break;
            case '4':
                if (input.hasText()) {
                    output.show(input);

                    std::cout << "\nSave text to file? (Y/N): ";
                    char saveChoice;
                    std::cin >> saveChoice;
                    if (saveChoice == 'Y' || saveChoice == 'y') {
                        output.saveToFile(input, "Kursach.txt");
                        db->exec("INSERT INTO TextEntries (text) VALUES ('" + input.getTextAsString() + "');");
                        std::cout << "Text saved." << std::endl;
                    }
                } else {
                    std::cout << "Error: No text to display." << std::endl;
                }
                break;
            case '5':
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '5');

    return 0;
}
