#include <iostream>

using namespace std
DynamicArray::DynamicArray() : data(nullptr), currentSize(0), capacity(0) {}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::append(int value) {
    if (currentSize == capacity) {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        resize(newCapacity);
    }
    data[currentSize++] = value;
}

int& DynamicArray::at(size_t index) {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int& DynamicArray::at(size_t index) const {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

size_t DynamicArray::size() const {
    return currentSize;
}

bool DynamicArray::empty() const {
    return currentSize == 0;
}

void DynamicArray::resize(size_t newCapacity) {
    int* newData = new int[newCapacity];
    for (size_t i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}




int main() {
    DynamicArray arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);

    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    return 0;
}
