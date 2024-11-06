#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ����������� ���� �����������
class Observer {
public:
    virtual void update(const std::string& state) = 0;
    virtual ~Observer() = default;
};

// ����������� ���� ���'����, ���� �������� �������������
class Subject {
public:
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

// ���������� ���'���
class ConcreteSubject : public Subject {
public:
    void addObserver(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (auto& observer : observers) {
            observer->update(state);
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notifyObservers();
    }

    std::string getState() const {
        return state;
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
    std::string state;
};

// ���������� ����������
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& state) override {
        std::cout << "Observer " << name << " updated with new state: " << state << std::endl;
    }

private:
    std::string name;
};

// ���������� ���
int main() {
    auto subject = std::make_shared<ConcreteSubject>();

    auto observer1 = std::make_shared<ConcreteObserver>("Observer 1");
    auto observer2 = std::make_shared<ConcreteObserver>("Observer 2");

    subject->addObserver(observer1);
    subject->addObserver(observer2);

    subject->setState("State #1");  // ������ ������������ ��� ���� �����

    subject->setState("State #2");  // ������ ������������ ��� ���� �����

    return 0;
}
