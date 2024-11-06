#include <iostream>
#include <memory>
#include <vector>

// ��������� �������
class Command {
public:
    virtual void execute() const = 0;
    virtual ~Command() = default;
};

// ��������� ������� ��� ��������� �����
class LightOnCommand : public Command {
public:
    LightOnCommand(class Light* light) : light(light) {}

    void execute() const override;

private:
    class Light* light;  // ��������� �� ��'���, ���� ���� ���������� ��������
};

// ��������� ������� ��� ��������� �����
class LightOffCommand : public Command {
public:
    LightOffCommand(class Light* light) : light(light) {}

    void execute() const override;

private:
    class Light* light;
};

// �������, ���� ������ ������ (������ ��'����, ����� ���� �������)
class Light {
public:
    void on() const {
        std::cout << "Light is ON." << std::endl;
    }

    void off() const {
        std::cout << "Light is OFF." << std::endl;
    }
};

// ���� Invoker, ���� ������ ��������� ������
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> command) {
        this->command = std::move(command);
    }

    void pressButton() const {
        command->execute();  // ���������� �������
    }

private:
    std::shared_ptr<Command> command;
};

// ��������� ������
void LightOnCommand::execute() const {
    light->on();  // ��������� ����� on ��'���� Light
}

void LightOffCommand::execute() const {
    light->off();  // ��������� ����� off ��'���� Light
}

// ���������� ���
int main() {
    Light light;  // ��������� ��'��� Light
    std::shared_ptr<Command> lightOn = std::make_shared<LightOnCommand>(&light);  // ��������� ������� ��� ���������
    std::shared_ptr<Command> lightOff = std::make_shared<LightOffCommand>(&light);  // ��������� ������� ��� ���������

    RemoteControl remote;  // ��������� �����

    // ������� �����
    remote.setCommand(lightOn);
    remote.pressButton();

    // �������� �����
    remote.setCommand(lightOff);
    remote.pressButton();

    return 0;
}
