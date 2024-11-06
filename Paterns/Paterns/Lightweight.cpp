#include <iostream>
#include <unordered_map>
#include <memory>

// ��������� ��� ��������, ������� ����� ������������ ������� ������������
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
    virtual ~Flyweight() = default;
};

// ���������� ������������
class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "Intrinsic State: " << intrinsicState << ", Extrinsic State: " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState;  // ����� ������ ��� ���� �������� ������ ����
};

// ������� ��������������
class FlyweightFactory {
public:
    // ���������� ��� ������� ������������
    std::shared_ptr<Flyweight> getFlyweight(const std::string& intrinsicState) {
        auto it = flyweights.find(intrinsicState);
        if (it != flyweights.end()) {
            return it->second;  // ���� ������ � ����� ���������� ��� ����������, ���������� ���
        }
        else {
            auto flyweight = std::make_shared<ConcreteFlyweight>(intrinsicState);
            flyweights[intrinsicState] = flyweight;
            return flyweight;  // ������� ����� ������, ���� ��� ��� ���
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;  // ������� ��� �������� ��� ��������� ��������
};

// ���������� ���
int main() {
    FlyweightFactory factory;

    // ���������� ���������� ������������� ��� ���������� ���������
    auto flyweight1 = factory.getFlyweight("sharedState1");
    auto flyweight2 = factory.getFlyweight("sharedState1");  // ���� ������ ����� ����������� � ������

    // ������� ������ ������� � ����������� �����������
    flyweight1->operation("uniqueState1");
    flyweight2->operation("uniqueState2");

    auto flyweight3 = factory.getFlyweight("sharedState2");
    flyweight3->operation("uniqueState3");

    // ��� ������������� � ���������� ���������� ���������� ���� ������
    std::cout << "flyweight1 and flyweight2 are the same object: "
        << (flyweight1 == flyweight2 ? "Yes" : "No") << std::endl;

    return 0;
}
