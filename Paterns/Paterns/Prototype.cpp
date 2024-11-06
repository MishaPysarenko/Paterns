#include <iostream>
#include <memory>
#include <string>

// Абстрактный класс Прототип
class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void show() const = 0;
    virtual ~Prototype() = default;
};

// Конкретный класс Прототипа
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(std::string name) : name(name) {}

    std::unique_ptr<Prototype> clone() const override {
        // Создаем новый объект, копируя данные из текущего
        return std::make_unique<ConcretePrototype>(*this);
    }

    void show() const override {
        std::cout << "Prototype name: " << name << std::endl;
    }

private:
    std::string name;
};

// Клиентский код
int main() {
    // Создаем исходный объект
    std::unique_ptr<Prototype> prototype1 = std::make_unique<ConcretePrototype>("Prototype1");

    // Клонируем объект
    std::unique_ptr<Prototype> prototype2 = prototype1->clone();

    // Показываем оригинальный и клонированный объекты
    prototype1->show();  // Выведет: Prototype name: Prototype1
    prototype2->show();  // Выведет: Prototype name: Prototype1

    return 0;
}
