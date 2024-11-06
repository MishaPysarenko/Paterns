#include <iostream>
#include <memory>

// Интерфейс для реального объекта
class RealSubject {
public:
    virtual void request() const {
        std::cout << "RealSubject: Request executed." << std::endl;
    }

    virtual ~RealSubject() = default;
};

// Заместитель (Proxy), который управляет доступом к реальному объекту
class Proxy : public RealSubject {
public:
    Proxy(std::shared_ptr<RealSubject> realSubject) : realSubject(std::move(realSubject)) {}

    void request() const override {
        std::cout << "Proxy: Checking conditions before forwarding request." << std::endl;

        // Применяем дополнительные действия, например, проверку доступа или логирование
        if (checkAccess()) {
            realSubject->request();  // Перенаправляем запрос к реальному объекту
            logAccess();
        }
    }

private:
    bool checkAccess() const {
        std::cout << "Proxy: Checking access." << std::endl;
        return true;  // Здесь можно добавить проверку доступа или другие условия
    }

    void logAccess() const {
        std::cout << "Proxy: Logging access." << std::endl;
    }

    std::shared_ptr<RealSubject> realSubject;  // Указатель на реальный объект
};

// Клиентский код
int main() {
    // Создаем реальный объект
    std::shared_ptr<RealSubject> realSubject = std::make_shared<RealSubject>();

    // Создаем прокси-объект, который управляет доступом к реальному объекту
    Proxy proxy(realSubject);

    // Клиент взаимодействует с прокси, который контролирует доступ к реальному объекту
    proxy.request();

    return 0;
}
