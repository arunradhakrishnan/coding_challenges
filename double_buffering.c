
// Double Buffering Overview
// Double buffering is a technique used to optimize data processing and synchronization in systems where reading and writing operations occur simultaneously, such as video streams or real-time applications. It involves using two buffers alternately to minimize delays and avoid data corruption during simultaneous access.

// How It Works
// Buffer Allocation:

// Two buffers of equal size are allocated in memory, typically called Buffer A and Buffer B.
// One buffer serves as the active (front) buffer for reading, while the other acts as the inactive (back) buffer for writing.
// Write Operations:

// Data (e.g., video frames) is written to the inactive buffer (back buffer).
// Once writing to the back buffer is complete, the buffers swap roles: the back buffer becomes the new front buffer, and vice versa.
// Read Operations:

// Data is read only from the front buffer. This ensures the reader always accesses consistent data, while the writer updates the other buffer.
// Synchronization:

// A synchronization mechanism ensures the swap happens only when:
// Writing to the back buffer is complete.
// Reading from the front buffer is finished.
// This prevents the reader from accessing incomplete data or the writer from overwriting active data.
// Illustration of Double Buffering
// Time Step	Buffer A (Front)	Buffer B (Back)	Action
// T0	Read	Write	Data is read from A; data is written to B.
// T1	Write	Read	Buffers swap roles. Writing starts on A, and reading switches to B.
// T2	Read	Write	Buffers swap roles again. Reading starts on A, and writing switches to B.
// Advantages
// Smooth Data Flow: The writer and reader work in parallel, minimizing wait times.
// Data Consistency: The reader always accesses fully updated data, avoiding partial writes.
// Real-Time Performance: Suitable for real-time systems where delays are unacceptable.




#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define FRAME_SIZE 1024 // Example frame size
#define BUFFER_COUNT 2  // Two buffers for double buffering

typedef struct {
    unsigned char data[FRAME_SIZE];
    int size; // Size of the frame data
} Frame;

// Buffers
Frame buffers[BUFFER_COUNT];
int front_buffer = 0;  // Index of the buffer being read
int back_buffer = 1;   // Index of the buffer being written

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready_to_swap = 0;

// Writer thread
void *writer(void *arg) {
    while (1) {
        // Simulate writing data to the back buffer
        printf("Writer: Writing to buffer %d\n", back_buffer);
        memset(buffers[back_buffer].data, 0xFF, FRAME_SIZE); // Dummy data
        buffers[back_buffer].size = FRAME_SIZE;

        // Signal that writing is complete
        pthread_mutex_lock(&lock);
        ready_to_swap = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);

        sleep(1); // Simulate frame interval
    }
}

// Reader thread
void *reader(void *arg) {
    while (1) {
        // Wait until writing is complete
        pthread_mutex_lock(&lock);
        while (!ready_to_swap) {
            pthread_cond_wait(&cond, &lock);
        }

        // Swap buffers
        int temp = front_buffer;
        front_buffer = back_buffer;
        back_buffer = temp;
        ready_to_swap = 0;

        pthread_mutex_unlock(&lock);

        // Read data from the front buffer
        printf("Reader: Reading from buffer %d\n", front_buffer);
        usleep(500000); // Simulate processing delay
    }
}

int main() {
    pthread_t writer_thread, reader_thread;

    // Create threads
    pthread_create(&writer_thread, NULL, writer, NULL);
    pthread_create(&reader_thread, NULL, reader, NULL);

    // Wait for threads to finish (they won't in this example)
    pthread_join(writer_thread, NULL);
    pthread_join(reader_thread, NULL);

    return 0;
}