#include <iostream>
#include <vector>
#include <memory>

// Абстрактный класс компонента
class Component {
public:
    virtual void operation() const = 0;  // Абстрактный метод операции
    virtual ~Component() = default;
};

// Лист (leaf) - конечный объект
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Композит (Composite) - контейнер для дочерних компонентов
class Composite : public Component {
public:
    void add(std::shared_ptr<Component> component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation" << std::endl;
        // Вызываем операцию для всех дочерних компонентов
        for (const auto& child : children) {
            child->operation();
        }
    }

private:
    std::vector<std::shared_ptr<Component>> children;  // Список дочерних компонентов
};

// Клиентский код
int main() {
    // Создаем листья
    std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();

    // Создаем композит
    std::shared_ptr<Component> composite = std::make_shared<Composite>();

    // Добавляем листья в композит
    composite->add(leaf1);
    composite->add(leaf2);

    // Вызываем операцию для композита
    composite->operation();

    // Выведет:
    // Composite operation
    // Leaf operation
    // Leaf operation

    return 0;
}
