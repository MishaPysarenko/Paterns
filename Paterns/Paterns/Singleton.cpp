#include <iostream>
#include <mutex>

// ����� Singleton
class Singleton {
public:
    // ������� ����������� ����������� � �������� ������������, ����� �������� ����������� ����������
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // ����� ��� ��������� ���������� ������
    static Singleton* getInstance() {
        // ���������� ������� ��� ������������������ ��� �������� ����������
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
    // ��������� �����������, ����� ������������� �������� ����������� �����
    Singleton() {
        std::cout << "Singleton created." << std::endl;
    }

    // ��������� �� ������������ ��������� ������
    static Singleton* instance;
};

// ������������� ������������ ���������
Singleton* Singleton::instance = nullptr;

// ���������� ���
int main() {
    // �������� ������������ ��������� Singleton
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->show();  // �������: Singleton instance address: <����� ����������>

    // �������� ��� �� ����� ���������
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->show();  // �������: Singleton instance address: <����� ���� �� ����������>

    return 0;
}
