#include <iostream>

// Подсистема 1
class Subsystem1 {
public:
    void operation1() const {
        std::cout << "Subsystem1: operation1" << std::endl;
    }

    void operation2() const {
        std::cout << "Subsystem1: operation2" << std::endl;
    }
};

// Подсистема 2
class Subsystem2 {
public:
    void operation1() const {
        std::cout << "Subsystem2: operation1" << std::endl;
    }

    void operation2() const {
        std::cout << "Subsystem2: operation2" << std::endl;
    }
};

// Подсистема 3
class Subsystem3 {
public:
    void operation1() const {
        std::cout << "Subsystem3: operation1" << std::endl;
    }

    void operation2() const {
        std::cout << "Subsystem3: operation2" << std::endl;
    }
};

// Фасад
class Facade {
public:
    Facade(Subsystem1* sub1, Subsystem2* sub2, Subsystem3* sub3)
        : subsystem1(sub1), subsystem2(sub2), subsystem3(sub3) {}

    // Упрощенные методы, которые скрывают вызовы сложных операций подсистем
    void simplifiedOperation() const {
        std::cout << "Facade: simplified operation\n";
        subsystem1->operation1();
        subsystem2->operation1();
        subsystem3->operation1();
    }

    void complexOperation() const {
        std::cout << "Facade: complex operation\n";
        subsystem1->operation2();
        subsystem2->operation2();
        subsystem3->operation2();
    }

private:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;
    Subsystem3* subsystem3;
};

// Клиентский код
int main() {
    // Создаем объекты подсистем
    Subsystem1 sub1;
    Subsystem2 sub2;
    Subsystem3 sub3;

    // Создаем фасад, который упрощает взаимодействие с подсистемами
    Facade facade(&sub1, &sub2, &sub3);

    // Клиент взаимодействует с фасадом, не заботясь о сложности системы
    facade.simplifiedOperation();
    facade.complexOperation();

    // Выведет:
    // Facade: simplified operation
    // Subsystem1: operation1
    // Subsystem2: operation1
    // Subsystem3: operation1
    //
    // Facade: complex operation
    // Subsystem1: operation2
    // Subsystem2: operation2
    // Subsystem3: operation2

    return 0;
}
