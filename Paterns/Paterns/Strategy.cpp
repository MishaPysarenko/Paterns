#include <iostream>
#include <memory>

// ����������� ���� ������㳿
class Strategy {
public:
    virtual void execute() = 0;  // ��������� ���������
    virtual ~Strategy() = default;
};

// ��������� �������� 1
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

// ��������� �������� 2
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// ��������, �� ����������� ��������
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

// ���������� ���
int main() {
    Context context;

    // ��������� ���������� ��������
    std::shared_ptr<Strategy> strategyA = std::make_shared<ConcreteStrategyA>();
    std::shared_ptr<Strategy> strategyB = std::make_shared<ConcreteStrategyB>();

    // ������������ ������㳿 A � ��������� ��
    context.setStrategy(strategyA);
    context.executeStrategy();

    // ���� ������㳿 �� B � ��������� ��
    context.setStrategy(strategyB);
    context.executeStrategy();

    return 0;
}
