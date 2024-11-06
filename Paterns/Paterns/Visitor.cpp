#include <iostream>
#include <vector>

// ����������� ���� ��������
class Element {
public:
    virtual void accept(class Visitor& visitor) = 0;  // ����� ������� ���������
    virtual ~Element() = default;
};

// ����������� ���� ���������
class Visitor {
public:
    virtual void visit(class ConcreteElementA& element) = 0;  // ����� ��� ConcreteElementA
    virtual void visit(class ConcreteElementB& element) = 0;  // ����� ��� ConcreteElementB
    virtual ~Visitor() = default;
};

// ���������� ������� A
class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);  // ³���������� ��� ������� ���������
    }

    void operationA() {
        std::cout << "ConcreteElementA: operationA" << std::endl;
    }
};

// ���������� ������� B
class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);  // ³���������� ��� ������� ���������
    }

    void operationB() {
        std::cout << "ConcreteElementB: operationB" << std::endl;
    }
};

// ���������� ��������
class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementA& element) override {
        std::cout << "ConcreteVisitor: visiting ConcreteElementA" << std::endl;
        element.operationA();  // ��������� �������� �������� A
    }

    void visit(ConcreteElementB& element) override {
        std::cout << "ConcreteVisitor: visiting ConcreteElementB" << std::endl;
        element.operationB();  // ��������� �������� �������� B
    }
};

// ���������� ���
int main() {
    std::vector<Element*> elements;
    elements.push_back(new ConcreteElementA());
    elements.push_back(new ConcreteElementB());

    ConcreteVisitor visitor;  // ��������� ���������

    // ³������ �� ��������
    for (Element* element : elements) {
        element->accept(visitor);  // ����� ������� ������ ���� ���������
    }

    // �������� ���'��
    for (Element* element : elements) {
        delete element;
    }

    return 0;
}
