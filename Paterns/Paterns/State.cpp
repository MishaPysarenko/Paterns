#include <iostream>
#include <memory>

// ����������� ���� �����
class State {
public:
    virtual void handle() = 0;  // ���������� �������� ��� ������� �����
    virtual ~State() = default;
};

// ��������, ���� ������ �������� ����
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

// ���������� ���� 1
class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "Handling request in State A." << std::endl;
    }
};

// ���������� ���� 2
class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "Handling request in State B." << std::endl;
    }
};

// ���������� ���
int main() {
    Context context;

    // ��������� ���������� �����
    std::shared_ptr<State> stateA = std::make_shared<ConcreteStateA>();
    std::shared_ptr<State> stateB = std::make_shared<ConcreteStateB>();

    // ������������ ����� A
    context.setState(stateA);
    context.request();  // ����������� ����� ��� ����� A

    // ���� ����� �� B
    context.setState(stateB);
    context.request();  // ����������� ����� ��� ����� B

    return 0;
}
