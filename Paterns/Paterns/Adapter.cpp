#include <iostream>

// ������ ��������� (�����, ������� ����� ������������)
class OldSystem {
public:
    void oldRequest() {
        std::cout << "Old system request." << std::endl;
    }
};

// ����� ��������� (�����, ������� ������� ������)
class NewSystem {
public:
    virtual void newRequest() = 0;
    virtual ~NewSystem() = default;
};

// �������, ������� ����������� ������ ������� � ����� ���������
class Adapter : public NewSystem {
public:
    Adapter(OldSystem* oldSystem) : oldSystem(oldSystem) {}

    void newRequest() override {
        // ���������������� ������ � ������ �������
        oldSystem->oldRequest();
    }

private:
    OldSystem* oldSystem;  // ������ �� ������ �������
};

// ���������� ���
int main() {
    // ������� ������ �������
    OldSystem oldSystem;

    // ������� ������� ��� ������ �������, ����� ��� ��������������� ������ ����������
    NewSystem* newSystem = new Adapter(&oldSystem);

    // ������ ������ ���������� ����� ���������
    newSystem->newRequest();  // �������: Old system request.

    // ������� ������
    delete newSystem;

    return 0;
}
