#include <iostream>

// Старый интерфейс (класс, который нужно адаптировать)
class OldSystem {
public:
    void oldRequest() {
        std::cout << "Old system request." << std::endl;
    }
};

// Новый интерфейс (класс, который ожидает клиент)
class NewSystem {
public:
    virtual void newRequest() = 0;
    virtual ~NewSystem() = default;
};

// Адаптер, который преобразует старую систему в новый интерфейс
class Adapter : public NewSystem {
public:
    Adapter(OldSystem* oldSystem) : oldSystem(oldSystem) {}

    void newRequest() override {
        // Переадресовываем запрос к старой системе
        oldSystem->oldRequest();
    }

private:
    OldSystem* oldSystem;  // Ссылка на старую систему
};

// Клиентский код
int main() {
    // Создаем старую систему
    OldSystem oldSystem;

    // Создаем адаптер для старой системы, чтобы она соответствовала новому интерфейсу
    NewSystem* newSystem = new Adapter(&oldSystem);

    // Клиент теперь использует новый интерфейс
    newSystem->newRequest();  // Выведет: Old system request.

    // Очищаем память
    delete newSystem;

    return 0;
}
