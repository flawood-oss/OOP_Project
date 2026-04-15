#include "views/ConsoleView.h"
#include <iostream>

namespace views {

void ConsoleView::displayMenu() const {
    std::cout << "\n===== UNIVERSITY HR MANAGEMENT =====" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Add Lecturer" << std::endl;
    std::cout << "3. Display All" << std::endl;
    std::cout << "4. Remove Person" << std::endl;
    std::cout << "5. Sort by Income" << std::endl;
    std::cout << "6. View Total Budget" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Selection: ";
}

void ConsoleView::displayMessage(const std::string& msg) const {
    std::cout << ">> " << msg << std::endl;
}

void ConsoleView::displayPeople(const std::vector<std::unique_ptr<models::Person>>& people) const {
    if (people.empty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    std::cout << "\n--- Personnel List ---" << std::endl;
    for (const auto& p : people) {
        p->displayInfo();
    }
}

std::string ConsoleView::getInput(const std::string& prompt) const {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input;
}

int ConsoleView::getIntInput(const std::string& prompt) const {
    std::cout << prompt;
    int input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Enter a number: ";
    }
    return input;
}

double ConsoleView::getDoubleInput(const std::string& prompt) const {
    std::cout << prompt;
    double input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Enter a decimal: ";
    }
    return input;
}

} // namespace views
