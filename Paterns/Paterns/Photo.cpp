#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Клас-знімок, який зберігає стан
class Memento {
public:
    explicit Memento(const std::string& state) : state(state) {}

    std::string getState() const {
        return state;
    }

private:
    std::string state;
};

// Клас-ініціатор, чий стан буде зберігатися та відновлюватися
class Originator {
public:
    void setState(const std::string& state) {
        this->state = state;
    }

    std::string getState() const {
        return state;
    }

    // Створює знімок стану
    std::shared_ptr<Memento> createMemento() const {
        return std::make_shared<Memento>(state);
    }

    // Відновлює стан з знімка
    void restoreMemento(const std::shared_ptr<Memento>& memento) {
        state = memento->getState();
    }

private:
    std::string state;
};

// Клас-доглядач, який зберігає знімки, але не змінює їх
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

// Клиєнтський код
int main() {
    Originator originator;
    Caretaker caretaker;

    // Зміна стану об'єкта та збереження його в знімок
    originator.setState("State #1");
    std::cout << "Originator Current State: " << originator.getState() << std::endl;
    caretaker.addMemento(originator.createMemento());

    // Зміна стану
    originator.setState("State #2");
    std::cout << "Originator Current State: " << originator.getState() << std::endl;
    caretaker.addMemento(originator.createMemento());

    // Відновлення попереднього стану з знімка
    originator.restoreMemento(caretaker.getMemento(0));
    std::cout << "Originator Restored State: " << originator.getState() << std::endl;

    return 0;
}
