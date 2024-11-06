#include <iostream>
#include <string>

// Клас для збереження даних співробітника в базу даних
class EmployeeDatabase {
public:
    void saveToDatabase(const std::string& name) {
        // Збереження інформації в базу даних
        std::cout << "Saving employee " << name << " to database." << std::endl;
    }
};

// Клас для представлення співробітника
class Employee {
private:
    std::string name;
    int age;

public:
    Employee(std::string name, int age) : name(name), age(age) {}

    void printEmployeeDetails() {
        // Виведення деталей співробітника
        std::cout << "Employee: " << name << ", Age: " << age << std::endl;
    }

    std::string getName() { return name; }
    int getAge() { return age; }
};
