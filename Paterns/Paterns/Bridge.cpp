#include <iostream>

// ����������: ���������, ������� �������� � ����������� �������
class Abstraction {
public:
    virtual void operation() const = 0;
    virtual ~Abstraction() = default;
};

// ����������: ����������� ��������� ��� ����������
class Implementation {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementation() = default;
};

// ���������� ���������� 1
class ConcreteImplementationA : public Implementation {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementationA operation" << std::endl;
    }
};

// ���������� ���������� 2
class ConcreteImplementationB : public Implementation {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementationB operation" << std::endl;
    }
};

// ����������� ����������
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

// ���������� ���
int main() {
    // ������� ����������
    ConcreteImplementationA implA;
    ConcreteImplementationB implB;

    // ������� ����������, ������������ ������ ����������
    RefinedAbstraction abstractionA(&implA);
    RefinedAbstraction abstractionB(&implB);

    // ���������� ��� �������� � ������������, �� ���� � ����������
    abstractionA.operation();  // �������: RefinedAbstraction: ConcreteImplementationA operation
    abstractionB.operation();  // �������: RefinedAbstraction: ConcreteImplementationB operation

    return 0;
}
