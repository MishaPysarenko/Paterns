#include <iostream>
#include <memory>
#include <vector>

// Інтерфейс команди
class Command {
public:
    virtual void execute() const = 0;
    virtual ~Command() = default;
};

// Конкретна команда для ввімкнення світла
class LightOnCommand : public Command {
public:
    LightOnCommand(class Light* light) : light(light) {}

    void execute() const override;

private:
    class Light* light;  // Посилання на об'єкт, який буде керуватися командою
};

// Конкретна команда для вимкнення світла
class LightOffCommand : public Command {
public:
    LightOffCommand(class Light* light) : light(light) {}

    void execute() const override;

private:
    class Light* light;
};

// Приймач, який виконує запити (реальні об'єкти, якими керує команда)
class Light {
public:
    void on() const {
        std::cout << "Light is ON." << std::endl;
    }

    void off() const {
        std::cout << "Light is OFF." << std::endl;
    }
};

// Клас Invoker, який ініціює виконання команд
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> command) {
        this->command = std::move(command);
    }

    void pressButton() const {
        command->execute();  // Виконується команда
    }

private:
    std::shared_ptr<Command> command;
};

// Реалізація команд
void LightOnCommand::execute() const {
    light->on();  // Викликаємо метод on об'єкта Light
}

void LightOffCommand::execute() const {
    light->off();  // Викликаємо метод off об'єкта Light
}

// Клиєнтський код
int main() {
    Light light;  // Створюємо об'єкт Light
    std::shared_ptr<Command> lightOn = std::make_shared<LightOnCommand>(&light);  // Створюємо команду для ввімкнення
    std::shared_ptr<Command> lightOff = std::make_shared<LightOffCommand>(&light);  // Створюємо команду для вимкнення

    RemoteControl remote;  // Створюємо пульт

    // Вмикаємо світло
    remote.setCommand(lightOn);
    remote.pressButton();

    // Вимикаємо світло
    remote.setCommand(lightOff);
    remote.pressButton();

    return 0;
}
