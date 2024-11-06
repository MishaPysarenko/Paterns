#include <iostream>
#include <memory>

// ����������� ����� �������
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() = default;
};

// ���������� ����� �������� A
class ProductA : public Product {
public:
    void display() const override {
        std::cout << "Product A" << std::endl;
    }
};

// ���������� ����� �������� B
class ProductB : public Product {
public:
    void display() const override {
        std::cout << "Product B" << std::endl;
    }
};

// ����������� ����� Creator (�������)
class Creator {
public:
    virtual std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Creator() = default;
};

// ���������� ����� Creator ��� �������� Product A
class ConcreteCreatorA : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ProductA>();
    }
};

// ���������� ����� Creator ��� �������� Product B
class ConcreteCreatorB : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ProductB>();
    }
};

// ���������� ���
int main() {
    // ������������� ������ ��� �������� ���������
    std::unique_ptr<Creator> creatorA = std::make_unique<ConcreteCreatorA>();
    std::unique_ptr<Product> productA = creatorA->createProduct();
    productA->display();  // �������: Product A

    std::unique_ptr<Creator> creatorB = std::make_unique<ConcreteCreatorB>();
    std::unique_ptr<Product> productB = creatorB->createProduct();
    productB->display();  // �������: Product B

    return 0;
}
