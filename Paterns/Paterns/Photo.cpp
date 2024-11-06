#include <iostream>
#include <string>
#include <memory>
#include <vector>

// ����-�����, ���� ������ ����
class Memento {
public:
    explicit Memento(const std::string& state) : state(state) {}

    std::string getState() const {
        return state;
    }

private:
    std::string state;
};

// ����-��������, ��� ���� ���� ���������� �� �������������
class Originator {
public:
    void setState(const std::string& state) {
        this->state = state;
    }

    std::string getState() const {
        return state;
    }

    // ������� ����� �����
    std::shared_ptr<Memento> createMemento() const {
        return std::make_shared<Memento>(state);
    }

    // ³������� ���� � �����
    void restoreMemento(const std::shared_ptr<Memento>& memento) {
        state = memento->getState();
    }

private:
    std::string state;
};

// ����-��������, ���� ������ �����, ��� �� ����� ��
class Caretaker {
public:
    void addMemento(const std::shared_ptr<Memento>& memento) {
        mementos.push_back(memento);
    }

    std::shared_ptr<Memento> getMemento(int index) const {
        return mementos.at(index);
    }

private:
    std::vector<std::shared_ptr<Memento>> mementos;
};

// ���������� ���
int main() {
    Originator originator;
    Caretaker caretaker;

    // ���� ����� ��'���� �� ���������� ���� � �����
    originator.setState("State #1");
    std::cout << "Originator Current State: " << originator.getState() << std::endl;
    caretaker.addMemento(originator.createMemento());

    // ���� �����
    originator.setState("State #2");
    std::cout << "Originator Current State: " << originator.getState() << std::endl;
    caretaker.addMemento(originator.createMemento());

    // ³��������� ������������ ����� � �����
    originator.restoreMemento(caretaker.getMemento(0));
    std::cout << "Originator Restored State: " << originator.getState() << std::endl;

    return 0;
}
