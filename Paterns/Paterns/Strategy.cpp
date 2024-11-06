#include <iostream>
#include <memory>

// Абстрактний клас стратегії
class Strategy {
public:
    virtual void execute() = 0;  // Виконання алгоритму
    virtual ~Strategy() = default;
};

// Конкретна стратегія 1
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

// Конкретна стратегія 2
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// Контекст, що використовує стратегію
class Context {
public:
    void setStrategy(std::shared_ptr<Strategy> strategy) {
        currentStrategy = strategy;
    }

    void executeStrategy() {
        currentStrategy->execute();
    }

private:
    std::shared_ptr<Strategy> currentStrategy;
};

// Клиєнтський код
int main() {
    Context context;

    // Створення конкретних стратегій
    std::shared_ptr<Strategy> strategyA = std::make_shared<ConcreteStrategyA>();
    std::shared_ptr<Strategy> strategyB = std::make_shared<ConcreteStrategyB>();

    // Встановлення стратегії A і виконання її
    context.setStrategy(strategyA);
    context.executeStrategy();

    // Зміна стратегії на B і виконання її
    context.setStrategy(strategyB);
    context.executeStrategy();

    return 0;
}
