#pragma once
#include "models/Person.h"
#include <vector>
#include <memory>
#include <algorithm>

namespace models {

// Model Logic Class (SRP: Chỉ quản lý danh sách và tính toán)
class HRManager {
private:
    // Sử dụng smart pointers để tự động quản lý bộ nhớ (Modern C++)
    std::vector<std::unique_ptr<Person>> people;

public:
    void addPerson(std::unique_ptr<Person> person);
    bool removePerson(const std::string& id);
    Person* findPerson(const std::string& id) const;
    
    const std::vector<std::unique_ptr<Person>>& getAll() const { return people; }
    
    void sortByIncome();
    double calculateTotalBudget() const;
};

} // namespace models
