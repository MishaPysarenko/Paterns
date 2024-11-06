#include <iostream>
#include <memory>
#include <string>

// ����������� ��������, �� ������� ��������� ��� ������� ������ �� ��� �������� ������ ���
class Handler {
public:
    virtual void handleRequest(const std::string& request) = 0;
    virtual ~Handler() = default;

    void setNextHandler(std::shared_ptr<Handler> nextHandler) {
        nextHandler_ = nextHandler;
    }

protected:
    std::shared_ptr<Handler> nextHandler_;
};

// ���������� �������� 1
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handled the request." << std::endl;
        }
        else if (nextHandler_) {
            nextHandler_->handleRequest(request);  // �������� ����� ���������� ���������
        }
    }
};

// ���������� �������� 2
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handled the request." << std::endl;
        }
        else if (nextHandler_) {
            nextHandler_->handleRequest(request);  // �������� ����� ���������� ���������
        }
    }
};

// ���������� �������� 3
class ConcreteHandlerC : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "C") {
            std::cout << "ConcreteHandlerC handled the request." << std::endl;
        }
        else if (nextHandler_) {
            nextHandler_->handleRequest(request);  // �������� ����� ���������� ���������
        }
    }
};

// ����������� ���
int main() {
    // ��������� �������� ���������
    auto handlerA = std::make_shared<ConcreteHandlerA>();
    auto handlerB = std::make_shared<ConcreteHandlerB>();
    auto handlerC = std::make_shared<ConcreteHandlerC>();

    // ������� ������ ���������
    handlerA->setNextHandler(handlerB);
    handlerB->setNextHandler(handlerC);

    // ��������� ������ ����� ������ ���������
    handlerA->handleRequest("A");  // �������� ConcreteHandlerA
    handlerA->handleRequest("B");  // �������� ConcreteHandlerB
    handlerA->handleRequest("C");  // �������� ConcreteHandlerC
    handlerA->handleRequest("D");  // ����� �������� �� ��������

    return 0;
}
