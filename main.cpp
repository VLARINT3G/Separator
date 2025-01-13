/**
 * @file main.cpp
 * @brief Основной файл программы, отвечающий за запуск и взаимодействие между компонентами.
 */

#include <Input.h>
#include <Work.h>
#include <Out.h>
#include <Database.h>
#include <CreateTable.h>

#include <iostream>
#include <memory>

int main() {
    auto db = std::make_shared<Database>("text_processing.db");
    CreateTable table("TextEntries");
    table.AddTextColumn("text");

    if (!db->AddTable(table)) {
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
            case '1': {
                std::cin.ignore();
                std::cout << "Enter the text: ";
                std::string userText;
                std::getline(std::cin, userText);
                input.SetText(userText);
                break;
            }
            case '2': {
                if (input.HasText() && input.HasReplacement()) {
                    processor.ProcessText(input);
                    std::cout << "Text processed." << std::endl;
                } else {
                    std::cout << "Error: No text or replacement character provided." << std::endl;
                }
                break;
            }
            case '3': {
                std::cin.ignore();
                std::cout << "Enter delimiters (as a string of characters): ";
                std::string delimitersInput;
                std::getline(std::cin, delimitersInput);
                std::vector<char> delimiters(delimitersInput.begin(), delimitersInput.end());
                input.SetDelimiters(delimiters);

                std::cout << "Enter replacement character: ";
                char replacementChar;
                std::cin >> replacementChar;
                input.SetReplacement(replacementChar);
                break;
            }
            case '4': {
                if (input.HasText()) {
                    output.Show(input);

                    std::cout << "\nSave text to file? (Y/N): ";
                    char saveChoice;
                    std::cin >> saveChoice;
                    if (saveChoice == 'Y' || saveChoice == 'y') {
                        output.SaveToFile(input, "Kursach.txt");
                        db->Exec("INSERT INTO TextEntries (text) VALUES ('" + input.GetTextAsString() + "');");
                        std::cout << "Text saved." << std::endl;
                    }
                } else {
                    std::cout << "Error: No text to display." << std::endl;
                }
                break;
            }
            case '5':
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '5');

    return 0;
}
