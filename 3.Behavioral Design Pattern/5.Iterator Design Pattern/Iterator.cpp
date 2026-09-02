#include <iostream>
using namespace std;

// Data structure interface
class DataStructure {
public:
    virtual void add(int num) = 0;
    virtual ~DataStructure() {}
};

// Iterator interface
class Iterable {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
    virtual ~Iterable() {}
};

// Custom Vector
class MyVector : public DataStructure {
private:
    int arr[100];
    int size;

public:
    MyVector() {
        size = 0;
    }

    void add(int num) override {
        arr[size++] = num;
    }

    int get(int index) {
        return arr[index];
    }

    int getSize() {
        return size;
    }
};

// Iterator for MyVector
class MyVectorIterator : public Iterable {
private:
    MyVector* vector;
    int index;

public:
    MyVectorIterator(MyVector* vector) {
        this->vector = vector;
        this->index = 0;
    }

    bool hasNext() override {
        return index < vector->getSize();
    }

    int next() override {
        return vector->get(index++);
    }
};

int main() {

    MyVector v;

    v.add(10);
    v.add(20);
    v.add(30);
    v.add(40);

    MyVectorIterator iterator(&v);

    while (iterator.hasNext()) {
        cout << iterator.next() << endl;
    }

    return 0;
}