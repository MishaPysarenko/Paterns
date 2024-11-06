#include <iostream>
#include <memory>

// Абстрактный класс Продукт
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() = default;
};

// Конкретный класс Продукта A
class ProductA : public Product {
public:
    void display() const override {
        std::cout << "Product A" << std::endl;
    }
};

// Конкретный класс Продукта B
class ProductB : public Product {
public:
    void display() const override {
        std::cout << "Product B" << std::endl;
    }
};

// Абстрактный класс Creator (фабрика)
class Creator {
public:
    virtual std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Creator() = default;
};

// Конкретный класс Creator для создания Product A
class ConcreteCreatorA : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ProductA>();
    }
};

// Конкретный класс Creator для создания Product B
class ConcreteCreatorB : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ProductB>();
    }
};

// Клиентский код
int main() {
    // Использование фабрик для создания продуктов
    std::unique_ptr<Creator> creatorA = std::make_unique<ConcreteCreatorA>();
    std::unique_ptr<Product> productA = creatorA->createProduct();
    productA->display();  // Выведет: Product A

    std::unique_ptr<Creator> creatorB = std::make_unique<ConcreteCreatorB>();
    std::unique_ptr<Product> productB = creatorB->createProduct();
    productB->display();  // Выведет: Product B

    return 0;
}
