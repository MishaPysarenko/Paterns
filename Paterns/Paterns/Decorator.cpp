#include <iostream>

// Базовый интерфейс
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// Конкретная реализация компонента
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// Абстрактный декоратор
class Decorator : public Component {
public:
    Decorator(Component* component) : component(component) {}

    void operation() const override {
        // Декоратор может вызывать операцию компонента, но также добавлять собственные действия
        component->operation();
    }

protected:
    Component* component;  // Компонент, который будет декорироваться
};

// Конкретный декоратор 1
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    void operation() const override {
        // Добавляем дополнительную функциональность
        std::cout << "ConcreteDecoratorA adds behavior" << std::endl;
        Decorator::operation();  // Вызываем операцию базового компонента
    }
};

// Конкретный декоратор 2
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    void operation() const override {
        // Добавляем дополнительную функциональность
        std::cout << "ConcreteDecoratorB adds behavior" << std::endl;
        Decorator::operation();  // Вызываем операцию базового компонента
    }
};

// Клиентский код
int main() {
    // Создаем базовый компонент
    ConcreteComponent component;

    // Создаем декораторы, которые добавляют поведение к компоненту
    ConcreteDecoratorA decoratorA(&component);
    ConcreteDecoratorB decoratorB(&decoratorA);

    // Вызываем операцию с добавленным поведением
    decoratorB.operation();

    // Выведет:
    // ConcreteDecoratorB adds behavior
    // ConcreteDecoratorA adds behavior
    // ConcreteComponent operation

    return 0;
}
