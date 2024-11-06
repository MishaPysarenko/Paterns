#include <iostream>

// Абстракция: Интерфейс, который работает с реализующим классом
class Abstraction {
public:
    virtual void operation() const = 0;
    virtual ~Abstraction() = default;
};

// Реализация: Абстрактный интерфейс для реализации
class Implementation {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementation() = default;
};

// Конкретная реализация 1
class ConcreteImplementationA : public Implementation {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementationA operation" << std::endl;
    }
};

// Конкретная реализация 2
class ConcreteImplementationB : public Implementation {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementationB operation" << std::endl;
    }
};

// Расширенная абстракция
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementation* impl) : impl(impl) {}

    void operation() const override {
        std::cout << "RefinedAbstraction: ";
        impl->operationImpl();
    }

private:
    Implementation* impl;
};

// Клиентский код
int main() {
    // Создаем реализации
    ConcreteImplementationA implA;
    ConcreteImplementationB implB;

    // Создаем абстракции, использующие разные реализации
    RefinedAbstraction abstractionA(&implA);
    RefinedAbstraction abstractionB(&implB);

    // Клиентский код работает с абстракциями, не зная о реализации
    abstractionA.operation();  // Выведет: RefinedAbstraction: ConcreteImplementationA operation
    abstractionB.operation();  // Выведет: RefinedAbstraction: ConcreteImplementationB operation

    return 0;
}
