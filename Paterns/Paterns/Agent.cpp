#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Абстрактний клас посередника
class Mediator {
public:
    virtual void notify(const std::string& sender, const std::string& event) = 0;
    virtual ~Mediator() = default;
};

// Абстрактний клас учасника
class Participant {
public:
    Participant(Mediator* mediator) : mediator(mediator) {}

    virtual void send(const std::string& event) = 0;  // Відправка повідомлення через посередника
    virtual void receive(const std::string& event) = 0;  // Отримання повідомлення від посередника

protected:
    Mediator* mediator;
};

// Конкретний учасник 1
class ConcreteParticipantA : public Participant {
public:
    ConcreteParticipantA(Mediator* mediator) : Participant(mediator) {}

    void send(const std::string& event) override {
        std::cout << "ConcreteParticipantA sends: " << event << std::endl;
        mediator->notify("ConcreteParticipantA", event);  // Надсилає повідомлення посереднику
    }

    void receive(const std::string& event) override {
        std::cout << "ConcreteParticipantA receives: " << event << std::endl;
    }
};

// Конкретний учасник 2
class ConcreteParticipantB : public Participant {
public:
    ConcreteParticipantB(Mediator* mediator) : Participant(mediator) {}

    void send(const std::string& event) override {
        std::cout << "ConcreteParticipantB sends: " << event << std::endl;
        mediator->notify("ConcreteParticipantB", event);
    }

    void receive(const std::string& event) override {
        std::cout << "ConcreteParticipantB receives: " << event << std::endl;
    }
};

// Конкретний посередник
class ConcreteMediator : public Mediator {
public:
    void addParticipant(std::shared_ptr<Participant> participant) {
        participants.push_back(participant);
    }

    void notify(const std::string& sender, const std::string& event) override {
        for (auto& participant : participants) {
            // Повідомляємо всіх учасників, окрім того, хто надіслав подію
            if ((sender == "ConcreteParticipantA" && dynamic_cast<ConcreteParticipantA*>(participant.get()) == nullptr) ||
                (sender == "ConcreteParticipantB" && dynamic_cast<ConcreteParticipantB*>(participant.get()) == nullptr)) {
                participant->receive(event);
            }
        }
    }

private:
    std::vector<std::shared_ptr<Participant>> participants;
};

// Клиєнтський код
int main() {
    ConcreteMediator mediator;

    auto participantA = std::make_shared<ConcreteParticipantA>(&mediator);
    auto participantB = std::make_shared<ConcreteParticipantB>(&mediator);

    mediator.addParticipant(participantA);
    mediator.addParticipant(participantB);

    participantA->send("Hello from A!");  // Учасник A відправляє повідомлення
    participantB->send("Hello from B!");  // Учасник B відправляє повідомлення

    return 0;
}
