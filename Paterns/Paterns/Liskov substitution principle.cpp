#include <iostream>
#include <vector>

class Bird {
public:
    virtual void move() = 0;  // �����, ���� ������� ��� �����
};

class Sparrow : public Bird {
public:
    void move() override {
        std::cout << "The sparrow is flying." << std::endl;
    }
};

class Ostrich : public Bird {
public:
    void move() override {
        std::cout << "The ostrich is running." << std::endl;
    }
};

int main() {
    std::vector<Bird*> birds = { new Sparrow(), new Ostrich() };

    for (auto bird : birds) {
        bird->move();  // ����� ����� ���� ������ ���� �������� ��
    }

    // �������� ���'��
    for (auto bird : birds) {
        delete bird;
    }

    return 0;
}
