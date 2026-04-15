#include "controllers/AppController.h"
#include "models/Student.h"
#include "models/Lecturer.h"

namespace controllers {

AppController::AppController() : running(true) {}

void AppController::run() {
    while (running) {
        view.displayMenu();
        int choice = view.getIntInput("");

        switch (choice) {
            case 1: handleAddStudent(); break;
            case 2: handleAddLecturer(); break;
            case 3: view.displayPeople(model.getAll()); break;
            case 4: handleRemove(); break;
            case 5: 
                model.sortByIncome();
                view.displayMessage("Sorted by income descending.");
                view.displayPeople(model.getAll());
                break;
            case 6:
                view.displayMessage("Total Budget: $" + std::to_string(model.calculateTotalBudget()));
                break;
            case 0: running = false; break;
            default: view.displayMessage("Invalid choice!");
        }
    }
}

void AppController::handleAddStudent() {
    try {
        std::string id = view.getInput("Enter ID: ");
        std::string name = view.getInput("Enter Name: ");
        int age = view.getIntInput("Enter Age: ");
        double gpa = view.getDoubleInput("Enter GPA: ");
        
        model.addPerson(std::make_unique<models::Student>(id, name, age, gpa));
        view.displayMessage("Student added successfully.");
    } catch (const std::exception& e) {
        view.displayMessage("Error: " + std::string(e.what()));
    }
}

void AppController::handleAddLecturer() {
    try {
        std::string id = view.getInput("Enter ID: ");
        std::string name = view.getInput("Enter Name: ");
        int age = view.getIntInput("Enter Age: ");
        double salary = view.getDoubleInput("Enter Base Salary: ");
        int pubs = view.getIntInput("Enter Number of Publications: ");
        
        model.addPerson(std::make_unique<models::Lecturer>(id, name, age, salary, pubs));
        view.displayMessage("Lecturer added successfully.");
    } catch (const std::exception& e) {
        view.displayMessage("Error: " + std::string(e.what()));
    }
}

void AppController::handleRemove() {
    std::string id = view.getInput("Enter ID to remove: ");
    if (model.removePerson(id)) {
        view.displayMessage("Removed successfully.");
    } else {
        view.displayMessage("ID not found.");
    }
}

} // namespace controllers
