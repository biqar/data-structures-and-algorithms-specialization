#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::priority_queue;
using std::cout;
using std::max_element;

const int MAX_VAL = 100000;
const int MAX_ELEMENT = 400005;

//priority_queue <int> pq;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MaxHeap {
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MaxHeap() {
        heap_size = 0;
        capacity = MAX_ELEMENT;
        harr = new int[MAX_ELEMENT];
    }

    // to heapify a subtree with the root at given index
    void MaxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i]) smallest = l;
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
        if (smallest != i) {
            swap(&harr[i], &harr[smallest]);
            MaxHeapify(smallest);
        }
    }

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMax(){
        if (heap_size <= 0) return MAX_VAL;
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        // Store the minimum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MaxHeapify(0);

        return root;
    }

    // Decreases key value of key at index i to new_val
    void increaseKey(int i, int new_val) {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i]) {
           swap(&harr[i], &harr[parent(i)]);
           i = parent(i);
        }
    }

    // Returns the minimum key (key at root) from min heap
    int getMax() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i) {
        increaseKey(i, MAX_VAL);
        extractMax();
    }

    // Inserts a new key 'k'
    void insertKey(int k) {
        if (heap_size == capacity) {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the min heap property if it is violated
        while (i != 0 && harr[parent(i)] > harr[i]) {
           swap(&harr[i], &harr[parent(i)]);
           i = parent(i);
        }
    }
};

class StackWithMax {
    vector<int> stack;
    MaxHeap h;
    //int maxVal = MIN_VAL;

  public:
    void Push(int value) {
        //if(value > maxVal) maxVal = value;
        h.insertKey(value);
        stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        h.deleteKey(stack[stack.size()-1]);
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        //return *max_element(stack.begin(), stack.end());
        return h.getMax();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
