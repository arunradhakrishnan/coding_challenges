#include <iostream>
#include <vector>

using namespace std;

// Function to insert a new element into the min-heap
void insert_min_heap(vector<int>& heap, int value);
// Function to delete a node from the min-heap
void delete_min_heap(vector<int>& heap, int value);



// Function to insert a new element into the min-heap
void insert_min_heap(vector<int>& heap, int value)
{
    // Add the new element to the end of the heap
    heap.push_back(value);
    // Get the index of the last element
    int index = heap.size() - 1;
    // Compare the new element with its parent and swap if
    // necessary
    while (index > 0
           && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        // Move up the tree to the parent of the current
        // element
        index = (index - 1) / 2;
    }
}

// Function to delete a node from the min-heap
void delete_min_heap(vector<int>& heap, int value)
{
    // Find the index of the element to be deleted
    int index = -1;
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }
    // If the element is not found, return
    if (index == -1) {
        return;
    }
    // Replace the element to be deleted with the last
    // element
    heap[index] = heap[heap.size() - 1];
    // Remove the last element
    heap.pop_back();
    // Heapify the tree starting from the element at the
    // deleted index
    while (true) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;
        if (left_child < heap.size()
            && heap[left_child] < heap[smallest]) {
            smallest = left_child;
        }
        if (right_child < heap.size()
            && heap[right_child] < heap[smallest]) {
            smallest = right_child;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else {
            break;
        }
    }
}

// Main function to test the insert_min_heap and
// delete_min_heap functions
int main()
{
    vector<int> heap;
    int values[] = { 13, 16, 31, 41, 51, 100 };
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        insert_min_heap(heap, values[i]);
    }
    cout << "Initial heap: ";
    for (int j = 0; j < heap.size(); j++) {
        cout << heap[j] << " ";
    }
    cout << endl;

    delete_min_heap(heap, 13);
    cout << "Heap after deleting 13: ";
    for (int j = 0; j < heap.size(); j++) {
        cout << heap[j] << " ";
    }
    cout << endl;

    return 0;
}

//-----------------------------------------------------------------------------------------------

void minHeapify(vector<int> &arr, int i, int n) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest, n);
    }
}

int main_heapify() {
    vector<int> arr = {10, 5, 15, 2, 20, 30};

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    // Perform heapify operation on min-heap
    for (int i = arr.size()/2 - 1; i >= 0; i--)
        minHeapify(arr, i, arr.size());

    cout << "\nMin-Heap after heapify operation: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}