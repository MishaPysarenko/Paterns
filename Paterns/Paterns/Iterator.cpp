#include <iostream>
#include <vector>
#include <memory>

// ����������� ���� ���������
template<typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;  // ��������, �� � ��������� �������
    virtual T next() = 0;  // ������� ��������� �������
    virtual ~Iterator() = default;
};

// ����������� ���� ��������, ���� ������� ��������
template<typename T>
class Iterable {
public:
    virtual std::shared_ptr<Iterator<T>> createIterator() = 0;
    virtual ~Iterable() = default;
};

// ��������� ��������, ��� ������ Iterable
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

    // ���������� �������� ��� ���� ��������
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

// ���������� ���
int main() {
    // ��������� �������� �� ��������� ��������
    MyCollection<int> collection;
    collection.add(1);
    collection.add(2);
    collection.add(3);
    collection.add(4);

    // ��������� ���������
    auto iterator = collection.createIterator();

    // ������ �������� �������� ����� ��������
    while (iterator->hasNext()) {
        std::cout << "Next element: " << iterator->next() << std::endl;
    }

    return 0;
}
