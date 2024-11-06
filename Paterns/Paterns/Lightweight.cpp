#include <iostream>
#include <unordered_map>
#include <memory>

// Интерфейс для объектов, которые будут использовать паттерн Легковаговик
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
    virtual ~Flyweight() = default;
};

// Конкретный легковаговик
class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "Intrinsic State: " << intrinsicState << ", Extrinsic State: " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState;  // Общие данные для всех объектов одного типа
};

// Фабрика легковаговиков
class FlyweightFactory {
public:
    // Возвращает или создает легковаговик
    std::shared_ptr<Flyweight> getFlyweight(const std::string& intrinsicState) {
        auto it = flyweights.find(intrinsicState);
        if (it != flyweights.end()) {
            return it->second;  // Если объект с таким состоянием уже существует, возвращаем его
        }
        else {
            auto flyweight = std::make_shared<ConcreteFlyweight>(intrinsicState);
            flyweights[intrinsicState] = flyweight;
            return flyweight;  // Создаем новый объект, если его еще нет
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;  // Словарь для хранения уже созданных объектов
};

// Клиентский код
int main() {
    FlyweightFactory factory;

    // Используем одинаковые легковаговики для одинаковых состояний
    auto flyweight1 = factory.getFlyweight("sharedState1");
    auto flyweight2 = factory.getFlyweight("sharedState1");  // Этот объект будет разделяться с первым

    // Создаем разные объекты с уникальными состояниями
    flyweight1->operation("uniqueState1");
    flyweight2->operation("uniqueState2");

    auto flyweight3 = factory.getFlyweight("sharedState2");
    flyweight3->operation("uniqueState3");

    // Все легковаговики с одинаковым состоянием используют один объект
    std::cout << "flyweight1 and flyweight2 are the same object: "
        << (flyweight1 == flyweight2 ? "Yes" : "No") << std::endl;

    return 0;
}
