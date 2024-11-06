#include <iostream>

// ������� ���������
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// ���������� ���������� ����������
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// ����������� ���������
class Decorator : public Component {
public:
    Decorator(Component* component) : component(component) {}

    void operation() const override {
        // ��������� ����� �������� �������� ����������, �� ����� ��������� ����������� ��������
        component->operation();
    }

protected:
    Component* component;  // ���������, ������� ����� ��������������
};

// ���������� ��������� 1
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    void operation() const override {
        // ��������� �������������� ����������������
        std::cout << "ConcreteDecoratorA adds behavior" << std::endl;
        Decorator::operation();  // �������� �������� �������� ����������
    }
};

// ���������� ��������� 2
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    void operation() const override {
        // ��������� �������������� ����������������
        std::cout << "ConcreteDecoratorB adds behavior" << std::endl;
        Decorator::operation();  // �������� �������� �������� ����������
    }
};

// ���������� ���
int main() {
    // ������� ������� ���������
    ConcreteComponent component;

    // ������� ����������, ������� ��������� ��������� � ����������
    ConcreteDecoratorA decoratorA(&component);
    ConcreteDecoratorB decoratorB(&decoratorA);

    // �������� �������� � ����������� ����������
    decoratorB.operation();

    // �������:
    // ConcreteDecoratorB adds behavior
    // ConcreteDecoratorA adds behavior
    // ConcreteComponent operation

    return 0;
}
