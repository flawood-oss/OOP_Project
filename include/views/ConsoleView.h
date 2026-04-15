#pragma once
#include "models/Person.h"
#include <vector>
#include <memory>

namespace views {

class ConsoleView {
public:
    void displayMenu() const;
    void displayMessage(const std::string& msg) const;
    void displayPeople(const std::vector<std::unique_ptr<models::Person>>& people) const;
    
    // Helper to get input
    std::string getInput(const std::string& prompt) const;
    int getIntInput(const std::string& prompt) const;
    double getDoubleInput(const std::string& prompt) const;
};

} // namespace views
