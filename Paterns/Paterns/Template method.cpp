#include <iostream>

// ����������� ����, �� ������� ��������� �����
class AbstractClass {
public:
    // ��������� �����, �� ������� ��������� ��������
    void templateMethod() {
        stepOne();
        stepTwo();
        stepThree();
    }

protected:
    // ��������� ������, �� ������ ���� ��������� � ��������
    virtual void stepOne() = 0;
    virtual void stepTwo() = 0;
    virtual void stepThree() = 0;
};

// ���������� ���� 1, �� ������ ������� ���������
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

// ���������� ���� 2, �� ������ ������� ���������
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

// ���������� ���
int main() {
    ConcreteClassA classA;
    ConcreteClassB classB;

    std::cout << "Executing template method in ConcreteClassA:" << std::endl;
    classA.templateMethod();  // ��������� ���������� ������ ��� ConcreteClassA

    std::cout << "\nExecuting template method in ConcreteClassB:" << std::endl;
    classB.templateMethod();  // ��������� ���������� ������ ��� ConcreteClassB

    return 0;
}
