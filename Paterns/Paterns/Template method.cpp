#include <iostream>

// Абстрактний клас, що визначає шаблонний метод
class AbstractClass {
public:
    // Шаблонний метод, що визначає загальний алгоритм
    void templateMethod() {
        stepOne();
        stepTwo();
        stepThree();
    }

protected:
    // Абстрактні методи, які повинні бути реалізовані в підкласах
    virtual void stepOne() = 0;
    virtual void stepTwo() = 0;
    virtual void stepThree() = 0;
};

// Конкретний клас 1, що реалізує частини алгоритму
class ConcreteClassA : public AbstractClass {
protected:
    void stepOne() override {
        std::cout << "ConcreteClassA: Step One" << std::endl;
    }

    void stepTwo() override {
        std::cout << "ConcreteClassA: Step Two" << std::endl;
    }

    void stepThree() override {
        std::cout << "ConcreteClassA: Step Three" << std::endl;
    }
};

// Конкретний клас 2, що реалізує частини алгоритму
class ConcreteClassB : public AbstractClass {
protected:
    void stepOne() override {
        std::cout << "ConcreteClassB: Step One" << std::endl;
    }

    void stepTwo() override {
        std::cout << "ConcreteClassB: Step Two" << std::endl;
    }

    void stepThree() override {
        std::cout << "ConcreteClassB: Step Three" << std::endl;
    }
};

// Клиєнтський код
int main() {
    ConcreteClassA classA;
    ConcreteClassB classB;

    std::cout << "Executing template method in ConcreteClassA:" << std::endl;
    classA.templateMethod();  // Виконання шаблонного методу для ConcreteClassA

    std::cout << "\nExecuting template method in ConcreteClassB:" << std::endl;
    classB.templateMethod();  // Виконання шаблонного методу для ConcreteClassB

    return 0;
}
