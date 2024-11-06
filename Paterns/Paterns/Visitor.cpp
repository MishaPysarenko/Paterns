#include <iostream>
#include <vector>

// Абстрактний клас елемента
class Element {
public:
    virtual void accept(class Visitor& visitor) = 0;  // Метод прийому відвідувача
    virtual ~Element() = default;
};

// Абстрактний клас відвідувача
class Visitor {
public:
    virtual void visit(class ConcreteElementA& element) = 0;  // Метод для ConcreteElementA
    virtual void visit(class ConcreteElementB& element) = 0;  // Метод для ConcreteElementB
    virtual ~Visitor() = default;
};

// Конкретний елемент A
class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);  // Відправляємо сам елемент відвідувачу
    }

    void operationA() {
        std::cout << "ConcreteElementA: operationA" << std::endl;
    }
};

// Конкретний елемент B
class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);  // Відправляємо сам елемент відвідувачу
    }

    void operationB() {
        std::cout << "ConcreteElementB: operationB" << std::endl;
    }
};

// Конкретний відвідувач
class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementA& element) override {
        std::cout << "ConcreteVisitor: visiting ConcreteElementA" << std::endl;
        element.operationA();  // Викликаємо операцію елемента A
    }

    void visit(ConcreteElementB& element) override {
        std::cout << "ConcreteVisitor: visiting ConcreteElementB" << std::endl;
        element.operationB();  // Викликаємо операцію елемента B
    }
};

// Клиєнтський код
int main() {
    std::vector<Element*> elements;
    elements.push_back(new ConcreteElementA());
    elements.push_back(new ConcreteElementB());

    ConcreteVisitor visitor;  // Створюємо відвідувача

    // Відвідуємо всі елементи
    for (Element* element : elements) {
        element->accept(visitor);  // Кожен елемент передає себе відвідувачу
    }

    // Очищення пам'яті
    for (Element* element : elements) {
        delete element;
    }

    return 0;
}
