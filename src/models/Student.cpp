#include "models/Student.h"
#include <iostream>
#include <iomanip>

namespace models {

Student::Student(const std::string& id, const std::string& name, int age, double gpa)
    : Person(id, name, age) {
    setGpa(gpa);
}

double Student::calculateIncome() const {
    // Sinh viên có thể nhận học bổng dựa trên GPA
    return (gpa >= 3.6) ? 500.0 : 0.0;
}

void Student::displayInfo() const {
    std::cout << "[Student] ID: " << id 
              << " | Name: " << name 
              << " | Age: " << age 
              << " | GPA: " << std::fixed << std::setprecision(2) << gpa 
              << " | Scholarship: $" << calculateIncome() << std::endl;
}

void Student::setGpa(double gpa) {
    if (gpa < 0.0 || gpa > 4.0) {
        throw std::invalid_argument("GPA must be between 0.0 and 4.0");
    }
    this->gpa = gpa;
}

} // namespace models
