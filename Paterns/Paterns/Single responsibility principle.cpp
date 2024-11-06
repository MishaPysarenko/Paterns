#include <iostream>
#include <string>

// ���� ��� ���������� ����� ����������� � ���� �����
class EmployeeDatabase {
public:
    void saveToDatabase(const std::string& name) {
        // ���������� ���������� � ���� �����
        std::cout << "Saving employee " << name << " to database." << std::endl;
    }
};

// ���� ��� ������������� �����������
class Employee {
private:
    std::string name;
    int age;

public:
    Employee(std::string name, int age) : name(name), age(age) {}

    void printEmployeeDetails() {
        // ��������� ������� �����������
        std::cout << "Employee: " << name << ", Age: " << age << std::endl;
    }

    std::string getName() { return name; }
    int getAge() { return age; }
};
