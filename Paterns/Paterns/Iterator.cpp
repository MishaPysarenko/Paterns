#include <iostream>
#include <vector>
#include <memory>

// Абстрактний клас ітератора
template<typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;  // Перевіряє, чи є наступний елемент
    virtual T next() = 0;  // Повертає наступний елемент
    virtual ~Iterator() = default;
};

// Абстрактний клас колекції, який створює ітератор
template<typename T>
class Iterable {
public:
    virtual std::shared_ptr<Iterator<T>> createIterator() = 0;
    virtual ~Iterable() = default;
};

// Конкретна колекція, яка реалізує Iterable
template<typename T>
class MyCollection : public Iterable<T> {
public:
    void add(const T& item) {
        items.push_back(item);
    }

    std::shared_ptr<Iterator<T>> createIterator() override {
        return std::make_shared<MyCollectionIterator>(*this);
    }

    size_t size() const {
        return items.size();
    }

    T& operator[](size_t index) {
        return items[index];
    }

private:
    std::vector<T> items;

    // Конкретний ітератор для цієї колекції
    class MyCollectionIterator : public Iterator<T> {
    public:
        MyCollectionIterator(MyCollection& collection) : collection(collection), index(0) {}

        bool hasNext() const override {
            return index < collection.size();
        }

        T next() override {
            return collection[index++];
        }

    private:
        MyCollection& collection;
        size_t index;
    };
};

// Клиєнтський код
int main() {
    // Створення колекції та додавання елементів
    MyCollection<int> collection;
    collection.add(1);
    collection.add(2);
    collection.add(3);
    collection.add(4);

    // Створення ітератора
    auto iterator = collection.createIterator();

    // Перебір елементів колекції через ітератор
    while (iterator->hasNext()) {
        std::cout << "Next element: " << iterator->next() << std::endl;
    }

    return 0;
}
