#include <iostream>
#include <memory>
#include <vector>
#include <string>

// ����������� ���� �����������
class Mediator {
public:
    virtual void notify(const std::string& sender, const std::string& event) = 0;
    virtual ~Mediator() = default;
};

// ����������� ���� ��������
class Participant {
public:
    Participant(Mediator* mediator) : mediator(mediator) {}

    virtual void send(const std::string& event) = 0;  // ³������� ����������� ����� �����������
    virtual void receive(const std::string& event) = 0;  // ��������� ����������� �� �����������

protected:
    Mediator* mediator;
};

// ���������� ������� 1
class ConcreteParticipantA : public Participant {
public:
    ConcreteParticipantA(Mediator* mediator) : Participant(mediator) {}

    void send(const std::string& event) override {
        std::cout << "ConcreteParticipantA sends: " << event << std::endl;
        mediator->notify("ConcreteParticipantA", event);  // ������� ����������� �����������
    }

    void receive(const std::string& event) override {
        std::cout << "ConcreteParticipantA receives: " << event << std::endl;
    }
};

// ���������� ������� 2
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

// ���������� ����������
class ConcreteMediator : public Mediator {
public:
    void addParticipant(std::shared_ptr<Participant> participant) {
        participants.push_back(participant);
    }

    void notify(const std::string& sender, const std::string& event) override {
        for (auto& participant : participants) {
            // ����������� ��� ��������, ���� ����, ��� ������� ����
            if ((sender == "ConcreteParticipantA" && dynamic_cast<ConcreteParticipantA*>(participant.get()) == nullptr) ||
                (sender == "ConcreteParticipantB" && dynamic_cast<ConcreteParticipantB*>(participant.get()) == nullptr)) {
                participant->receive(event);
            }
        }
    }

private:
    std::vector<std::shared_ptr<Participant>> participants;
};

// ���������� ���
int main() {
    ConcreteMediator mediator;

    auto participantA = std::make_shared<ConcreteParticipantA>(&mediator);
    auto participantB = std::make_shared<ConcreteParticipantB>(&mediator);

    mediator.addParticipant(participantA);
    mediator.addParticipant(participantB);

    participantA->send("Hello from A!");  // ������� A ��������� �����������
    participantB->send("Hello from B!");  // ������� B ��������� �����������

    return 0;
}
