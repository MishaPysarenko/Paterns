#include <iostream>
#include <string>
#include <memory>

// Продукт, который будет строиться
class Product {
public:
    void addPart(const std::string& part) {
        parts += part + " ";
    }

    void show() const {
        std::cout << "Product parts: " << parts << std::endl;
    }

private:
    std::string parts;
};

// Абстрактный строитель
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual std::shared_ptr<Product> getResult() = 0;
    virtual ~Builder() = default;
};

// Конкретный строитель для создания конкретного продукта
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() {
        product = std::make_shared<Product>();
    }

    void buildPartA() override {
        product->addPart("Part A");
    }

    void buildPartB() override {
        product->addPart("Part B");
    }

    std::shared_ptr<Product> getResult() override {
        return product;
    }

private:
    std::shared_ptr<Product> product;
};

// Директор, который управляет процессом строительства
class Director {
public:
    void setBuilder(std::shared_ptr<Builder> builder) {
        this->builder = builder;
    }

    std::shared_ptr<Product> construct() {
        builder->buildPartA();
        builder->buildPartB();
        return builder->getResult();
    }

private:
    std::shared_ptr<Builder> builder;
};

// Клиентский код
int main() {
    // Создаем строитель и директора
    std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder>();
    Director director;
    director.setBuilder(builder);

    // Строим продукт
    std::shared_ptr<Product> product = director.construct();

    // Показываем результат
    product->show();  // Выведет: Product parts: Part A Part B 

    return 0;
}
