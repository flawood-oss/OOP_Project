#include "models/HRManager.h"

namespace models {

void HRManager::addPerson(std::unique_ptr<Person> person) {
    people.push_back(std::move(person));
}

bool HRManager::removePerson(const std::string& id) {
    auto it = std::remove_if(people.begin(), people.end(),
        [&id](const std::unique_ptr<Person>& p) { return p->getId() == id; });
    
    if (it != people.end()) {
        people.erase(it, people.end());
        return true;
    }
    return false;
}

Person* HRManager::findPerson(const std::string& id) const {
    for (const auto& p : people) {
        if (p->getId() == id) return p.get();
    }
    return nullptr;
}

void HRManager::sortByIncome() {
    std::sort(people.begin(), people.end(),
        [](const std::unique_ptr<Person>& a, const std::unique_ptr<Person>& b) {
            return a->calculateIncome() > b->calculateIncome();
        });
}

double HRManager::calculateTotalBudget() const {
    double total = 0;
    for (const auto& p : people) {
        total += p->calculateIncome();
    }
    return total;
}

} // namespace models
