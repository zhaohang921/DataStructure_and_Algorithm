#include <iostream>
#include <cassert>

template<typename T>
class MaxHeap {
public:
    MaxHeap() = default;
    MaxHeap(int capacity) : size(0), capacity(capacity) {
        data = new T[]
    }

private:
    T *data;
    int size;
    int capacity;
};