/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    void maxHeapify(int i, int heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heapSize && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest, heapSize);
        }
    }

public:
    void buildMaxHeap() {
        int heapSize = heap.size();

        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(i, heapSize);
        }
    }

    void heapsort() {
        int heapSize = heap.size();

        buildMaxHeap();

        for (int i = heapSize - 1; i >= 1; --i) {
            swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }

    void insert(int value) {
        heap.push_back(value);
    }

    void displayHeap() const {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heapObj;

    heapObj.insert(25);
    heapObj.insert(17);
    heapObj.insert(36);
    heapObj.insert(2);
    heapObj.insert(8);
    heapObj.insert(19);
    heapObj.insert(1);

    heapObj.heapsort();

    heapObj.displayHeap();

    return 0;
}

