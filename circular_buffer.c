#include <stdint.h>

#define BUFFER_SIZE 8

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    int head;
    int tail;
    int full;
} CircularBuffer;

void buffer_init(CircularBuffer* cb) {
	cb->head  = 0;
	cb->tail  = 0;
	cb->full = 0;
}

int push(CircularBuffer* cb, uint8_t data) {
    if (cb->full)
	return -1;  // Buffer full

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;

    if (cb->head == cb->tail) 
	cb->full = 1;

    return 0;
}

int pop(CircularBuffer* cb, uint8_t* data) {
    if (cb->head == cb->tail && !cb->full) 
        return -1;  // Buffer empty

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->full = 0;
    return 0;
}