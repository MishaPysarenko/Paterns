#include <iostream>
#include <mutex>

// Класс Singleton
class Singleton {
public:
    // Удаляем конструктор копирования и оператор присваивания, чтобы избежать копирования экземпляра
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Метод для получения экземпляра класса
    static Singleton* getInstance() {
        // Используем мьютекс для потокобезопасности при создании экземпляра
        static std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);

        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void show() const {
        std::cout << "Singleton instance address: " << this << std::endl;
    }

private:
    // Приватный конструктор, чтобы предотвратить создание экземпляров извне
    Singleton() {
        std::cout << "Singleton created." << std::endl;
    }

    // Указатель на единственный экземпляр класса
    static Singleton* instance;
};

// Инициализация статического указателя
Singleton* Singleton::instance = nullptr;

// Клиентский код
int main() {
    // Получаем единственный экземпляр Singleton
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->show();  // Выведет: Singleton instance address: <адрес экземпляра>

    // Получаем тот же самый экземпляр
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->show();  // Выведет: Singleton instance address: <адрес того же экземпляра>

    return 0;
}
