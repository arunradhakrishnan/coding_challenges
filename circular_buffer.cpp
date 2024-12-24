#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


using namespace std;
//template <typename T>

//write to the head .. read from the tail
class CircularBuffer {
public:

    int head;
    int tail; 
    bool full;
    int size;
    CircularBuffer(int size_) 
    {  
        buffer = new int[size_];
        size = size_;
        cout << "size " << size << "\n";
        head = 0 ; 
        tail = 0 ; 

    }

    void put(int item) {

        buffer[head] = item;
        head = (head + 1) % size;

        if (full) {
            tail = (tail + 1) % size;
        }

        if(head == tail)
            full  = true;
        else
            full = false;
    }

    int get() {
        if (empty()) {
            cout << "Buffer is empty";
        }

        int val = buffer[tail];
        tail = (tail + 1) % size;
        full = false;

        return val;
    }


    bool empty() const {
        return (!full && (head == tail));
    }



    int capacity() const {
        return size;
    }

    int current_size() const {
        int size = size;

        cout << "current size " << size << "\n";

        if (!full) {
            if (head >= tail) {
                cout <<  "head " << head << "tail " << tail << "\n";
                size = head - tail;
            } else {
                size = size + head - tail;
            }
        }

        return size;
    }

private:
    int * buffer;
    
};

int main() {
    CircularBuffer cb(5);  // buffer of size 5

    cb.put(1);
    cb.put(2);
    cb.put(3);
    cb.put(4);
    cb.put(5);

    
    std::cout << "Buffer size: " << cb.current_size() << "\n";

    std::cout << "Getting: " << cb.get() << "\n";
    std::cout << "Getting: " << cb.get() << "\n";

    cb.put(6);
    cb.put(7);

    
    std::cout << "Buffer size: " << cb.current_size() << "\n";

    while (!cb.empty()) {
        std::cout << "Getting: " << cb.get() << "\n";
    }

    return 0;
}
