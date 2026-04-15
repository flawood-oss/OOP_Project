#pragma once
#include "models/HRManager.h"
#include "views/ConsoleView.h"

namespace controllers {

class AppController {
private:
    models::HRManager model;
    views::ConsoleView view;
    bool running;

public:
    AppController();
    void run();

private:
    void handleAddStudent();
    void handleAddLecturer();
    void handleRemove();
};

} // namespace controllers
