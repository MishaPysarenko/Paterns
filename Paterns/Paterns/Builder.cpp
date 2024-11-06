#include <iostream>
#include <string>
#include <memory>

// �������, ������� ����� ���������
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

// ����������� ���������
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual std::shared_ptr<Product> getResult() = 0;
    virtual ~Builder() = default;
};

// ���������� ��������� ��� �������� ����������� ��������
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

// ��������, ������� ��������� ��������� �������������
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

// ���������� ���
int main() {
    // ������� ��������� � ���������
    std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder>();
    Director director;
    director.setBuilder(builder);

    // ������ �������
    std::shared_ptr<Product> product = director.construct();

    // ���������� ���������
    product->show();  // �������: Product parts: Part A Part B 

    return 0;
}
