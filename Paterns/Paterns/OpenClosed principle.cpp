#include <iostream>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;  // Метод для обчислення площі
    virtual ~Shape() = default;  // Віртуальний деструктор
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;  // Обчислення площі прямокутника
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;  // Обчислення площі кола
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;  // Обчислення площі трикутника
    }
};

class AreaCalculator {
public:
    double calculateTotalArea(const std::vector<Shape*>& shapes) {
        double total = 0;
        for (auto shape : shapes) {
            total += shape->area();  // Викликається метод area для кожної фігури
        }
        return total;
    }
};

int main() {
    std::vector<Shape*> shapes = { new Rectangle(3, 4), new Circle(5), new Triangle(4, 6) };

    AreaCalculator calculator;
    double totalArea = calculator.calculateTotalArea(shapes);

    std::cout << "Total area: " << totalArea << std::endl;

    // Очищення пам'яті
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
