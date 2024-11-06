#include <iostream>
#include <memory>

// ����������� �������� ��� ������� ���������
class AbstractProductA {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductA() = default;
};

class ProductA1 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Product A1" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Product A2" << std::endl;
    }
};

// ����������� �������� ��� ������� ���������
class AbstractProductB {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductB() = default;
};

class ProductB1 : public AbstractProductB {
public:
    void display() const override {
        std::cout << "Product B1" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
public:
    void display() const override {
        std::cout << "Product B2" << std::endl;
    }
};

// ����������� �������, ������� ������� ����������� ��������
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() = default;
};

// ���������� ������� ��� ������� ��������� ���������
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ProductB1>();
    }
};

// ���������� ������� ��� ������� ��������� ���������
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ProductB2>();
    }
};

// ���������� ���
int main() {
    // ������� ������� ��� ������� ��������� ���������
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProductA> productA1 = factory1->createProductA();
    std::unique_ptr<AbstractProductB> productB1 = factory1->createProductB();

    productA1->display();  // �������: Product A1
    productB1->display();  // �������: Product B1

    // ������� ������� ��� ������� ��������� ���������
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProductA> productA2 = factory2->createProductA();
    std::unique_ptr<AbstractProductB> productB2 = factory2->createProductB();

    productA2->display();  // �������: Product A2
    productB2->display();  // �������: Product B2

    return 0;
}
