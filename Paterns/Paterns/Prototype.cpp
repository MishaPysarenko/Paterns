#include <iostream>
#include <memory>
#include <string>

// ����������� ����� ��������
class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void show() const = 0;
    virtual ~Prototype() = default;
};

// ���������� ����� ���������
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(std::string name) : name(name) {}

    std::unique_ptr<Prototype> clone() const override {
        // ������� ����� ������, ������� ������ �� ��������
        return std::make_unique<ConcretePrototype>(*this);
    }

    void show() const override {
        std::cout << "Prototype name: " << name << std::endl;
    }

private:
    std::string name;
};

// ���������� ���
int main() {
    // ������� �������� ������
    std::unique_ptr<Prototype> prototype1 = std::make_unique<ConcretePrototype>("Prototype1");

    // ��������� ������
    std::unique_ptr<Prototype> prototype2 = prototype1->clone();

    // ���������� ������������ � ������������� �������
    prototype1->show();  // �������: Prototype name: Prototype1
    prototype2->show();  // �������: Prototype name: Prototype1

    return 0;
}
