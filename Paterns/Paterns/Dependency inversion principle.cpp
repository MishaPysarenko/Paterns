#include <iostream>

class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Switchable() = default;
};

class LightBulb : public Switchable {
public:
    void turnOn() override {
        std::cout << "LightBulb: Turning on." << std::endl;
    }

    void turnOff() override {
        std::cout << "LightBulb: Turning off." << std::endl;
    }
};

class Fan : public Switchable {
public:
    void turnOn() override {
        std::cout << "Fan: Starting." << std::endl;
    }

    void turnOff() override {
        std::cout << "Fan: Stopping." << std::endl;
    }
};

class Switch {
private:
    Switchable* device;  // ��������� �� ����������

public:
    Switch(Switchable* device) : device(device) {}

    void operate() {
        device->turnOn();  // ����������� �� ����� ����������
    }
};

int main() {
    LightBulb bulb;
    Switch lightSwitch(&bulb);
    lightSwitch.operate();  // ����������� ����� turnOn() ��������

    Fan fan;
    Switch fanSwitch(&fan);
    fanSwitch.operate();  // ����������� ����� turnOn() �����������

    return 0;
}
