#include <iostream>
#include <memory>

// Абстрактний клас стану
class State {
public:
    virtual void handle() = 0;  // Визначення поведінки для кожного стану
    virtual ~State() = default;
};

// Контекст, який зберігає поточний стан
class Context {
public:
    void setState(std::shared_ptr<State> state) {
        currentState = state;
    }

    void request() {
        currentState->handle();
    }

private:
    std::shared_ptr<State> currentState;
};

// Конкретний стан 1
class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "Handling request in State A." << std::endl;
    }
};

// Конкретний стан 2
class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "Handling request in State B." << std::endl;
    }
};

// Клиєнтський код
int main() {
    Context context;

    // Створення конкретних станів
    std::shared_ptr<State> stateA = std::make_shared<ConcreteStateA>();
    std::shared_ptr<State> stateB = std::make_shared<ConcreteStateB>();

    // Встановлення стану A
    context.setState(stateA);
    context.request();  // Викликається метод для стану A

    // Зміна стану на B
    context.setState(stateB);
    context.request();  // Викликається метод для стану B

    return 0;
}
