#include <iostream>

class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class HumanWorker : public Workable, public Eatable {
public:
    void work() override {
        std::cout << "Human is working." << std::endl;
    }

    void eat() override {
        std::cout << "Human is eating." << std::endl;
    }
};

class RobotWorker : public Workable {
public:
    void work() override {
        std::cout << "Robot is working." << std::endl;
    }
};

int main() {
    Workable* human = new HumanWorker();
    Workable* robot = new RobotWorker();

    human->work();
    // Не потрібно викликати eat() для людини, якщо це не потрібно в контексті

    robot->work();
    // Робот не залежить від методу eat()

    delete human;
    delete robot;

    return 0;
}
