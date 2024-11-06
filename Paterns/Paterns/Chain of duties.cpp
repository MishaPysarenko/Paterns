#include <iostream>
#include <memory>
#include <string>

// Абстрактний обробник, що визначає інтерфейс для обробки запиту та для передачі запиту далі
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

// Конкретний обробник 1
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handled the request." << std::endl;
        }
        else if (nextHandler_) {
            nextHandler_->handleRequest(request);  // Передаємо запит наступному обробнику
        }
    }
};

// Конкретний обробник 2
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handled the request." << std::endl;
        }
        else if (nextHandler_) {
            nextHandler_->handleRequest(request);  // Передаємо запит наступному обробнику
        }
    }
};

// Конкретний обробник 3
class ConcreteHandlerC : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "C") {
            std::cout << "ConcreteHandlerC handled the request." << std::endl;
        }
        else if (nextHandler_) {
            nextHandler_->handleRequest(request);  // Передаємо запит наступному обробнику
        }
    }
};

// Клиентський код
int main() {
    // Створюємо конкретні обробники
    auto handlerA = std::make_shared<ConcreteHandlerA>();
    auto handlerB = std::make_shared<ConcreteHandlerB>();
    auto handlerC = std::make_shared<ConcreteHandlerC>();

    // Формуємо ланцюг обробників
    handlerA->setNextHandler(handlerB);
    handlerB->setNextHandler(handlerC);

    // Надсилаємо запити через ланцюг обробників
    handlerA->handleRequest("A");  // Обробить ConcreteHandlerA
    handlerA->handleRequest("B");  // Обробить ConcreteHandlerB
    handlerA->handleRequest("C");  // Обробить ConcreteHandlerC
    handlerA->handleRequest("D");  // Жоден обробник не обробить

    return 0;
}
