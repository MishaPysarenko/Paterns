#include <iostream>
#include <memory>

// ��������� ��� ��������� �������
class RealSubject {
public:
    virtual void request() const {
        std::cout << "RealSubject: Request executed." << std::endl;
    }

    virtual ~RealSubject() = default;
};

// ����������� (Proxy), ������� ��������� �������� � ��������� �������
class Proxy : public RealSubject {
public:
    Proxy(std::shared_ptr<RealSubject> realSubject) : realSubject(std::move(realSubject)) {}

    void request() const override {
        std::cout << "Proxy: Checking conditions before forwarding request." << std::endl;

        // ��������� �������������� ��������, ��������, �������� ������� ��� �����������
        if (checkAccess()) {
            realSubject->request();  // �������������� ������ � ��������� �������
            logAccess();
        }
    }

private:
    bool checkAccess() const {
        std::cout << "Proxy: Checking access." << std::endl;
        return true;  // ����� ����� �������� �������� ������� ��� ������ �������
    }

    void logAccess() const {
        std::cout << "Proxy: Logging access." << std::endl;
    }

    std::shared_ptr<RealSubject> realSubject;  // ��������� �� �������� ������
};

// ���������� ���
int main() {
    // ������� �������� ������
    std::shared_ptr<RealSubject> realSubject = std::make_shared<RealSubject>();

    // ������� ������-������, ������� ��������� �������� � ��������� �������
    Proxy proxy(realSubject);

    // ������ ��������������� � ������, ������� ������������ ������ � ��������� �������
    proxy.request();

    return 0;
}
