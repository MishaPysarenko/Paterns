#include <iostream>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;  // ����� ��� ���������� �����
    virtual ~Shape() = default;  // ³��������� ����������
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;  // ���������� ����� ������������
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;  // ���������� ����� ����
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;  // ���������� ����� ����������
    }
};

class AreaCalculator {
public:
    double calculateTotalArea(const std::vector<Shape*>& shapes) {
        double total = 0;
        for (auto shape : shapes) {
            total += shape->area();  // ����������� ����� area ��� ����� ������
        }
        return total;
    }
};

int main() {
    std::vector<Shape*> shapes = { new Rectangle(3, 4), new Circle(5), new Triangle(4, 6) };

    AreaCalculator calculator;
    double totalArea = calculator.calculateTotalArea(shapes);

    std::cout << "Total area: " << totalArea << std::endl;

    // �������� ���'��
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
