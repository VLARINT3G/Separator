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
      std::cout << "\nMenu:\n"
                << "1) Enter text\n"
                << "2) Process the text\n"
                << "3) Put the sepatator and replacement symbol\n"
                << "4) Show text\n"
                << "5) Quit\n"
                << "Choose option: ";
      std::cin >> choice;

      switch (choice) {
        case '1': {
          std::cout << "Write down the text: ";
          std::cin.ignore();
          std::string text;
          std::getline(std::cin, text);
          input.SetText(text);
          break;
        }
        case '2': {
          processor.ProcessText(input);
          std::cout << "Text has been prossed." << std::endl;
          break;
        }
        case '3': {
          std::cout << "Write down the separator (without blank space): ";
          std::string delimitersInput;
          std::cin >> delimitersInput;
          input.SetDelimiters(std::vector<char>(delimitersInput.begin(), delimitersInput.end()));

          std::cout << "Enter the replacement character: ";
          char replacement;
          std::cin >> replacement;
          input.SetReplacement(replacement);
          break;
        }
        case '4': {
          std::cout << "Current text: " << input.GetText() << std::endl;
          break;
        }
        case '5': {
          std::cout << "Exit." << std::endl;
          break;
        }
        default:std::cout << "Invalid input. Try again." << std::endl;
      }
    } while (choice != '5');
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
