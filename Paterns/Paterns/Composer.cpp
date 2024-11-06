#include <iostream>
#include <vector>
#include <memory>

// ����������� ����� ����������
class Component {
public:
    virtual void operation() const = 0;  // ����������� ����� ��������
    virtual ~Component() = default;
};

// ���� (leaf) - �������� ������
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// �������� (Composite) - ��������� ��� �������� �����������
class Composite : public Component {
public:
    void add(std::shared_ptr<Component> component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation" << std::endl;
        // �������� �������� ��� ���� �������� �����������
        for (const auto& child : children) {
            child->operation();
        }
    }

private:
    std::vector<std::shared_ptr<Component>> children;  // ������ �������� �����������
};

// ���������� ���
int main() {
    // ������� ������
    std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();

    // ������� ��������
    std::shared_ptr<Component> composite = std::make_shared<Composite>();

    // ��������� ������ � ��������
    composite->add(leaf1);
    composite->add(leaf2);

    // �������� �������� ��� ���������
    composite->operation();

    // �������:
    // Composite operation
    // Leaf operation
    // Leaf operation

    return 0;
}
