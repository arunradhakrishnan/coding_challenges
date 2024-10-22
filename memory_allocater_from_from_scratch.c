#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define MEMORY_POOL_SIZE 1024  // Size of the memory pool (in bytes)
#define BLOCK_SIZE 16          // Size of each memory block (must be a power of 2)

// Memory pool and control structures
static uint8_t memory_pool[MEMORY_POOL_SIZE];
static uint8_t block_map[MEMORY_POOL_SIZE / BLOCK_SIZE]; // 0 = free, 1 = allocated

// Initialize the memory pool
void memory_init() {
    for (size_t i = 0; i < sizeof(block_map); ++i) {
        block_map[i] = 0; // All blocks are free
    }
}

// Find the first free block of the required size
void *memory_alloc(size_t size) {
    if (size == 0 || size > MEMORY_POOL_SIZE) {
        return NULL;
    }
    size_t num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    size_t free_blocks = 0;

    for (size_t i = 0; i < sizeof(block_map); ++i) {
        if (block_map[i] == 0) {
            ++free_blocks;
            if (free_blocks == num_blocks) {
                // Found a sufficient number of free blocks
                for (size_t j = i - free_blocks + 1; j <= i; ++j) {
                    block_map[j] = 1; // Mark blocks as allocated
                }
                return &memory_pool[(i - free_blocks + 1) * BLOCK_SIZE];
            }
        } else {
            free_blocks = 0; // Reset count if we encounter an allocated block
        }
    }
    return NULL; // No sufficient free block found
}

// Free allocated memory
void memory_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }
    size_t offset = (uint8_t *)ptr - memory_pool;
    size_t block_index = offset / BLOCK_SIZE;

    while (block_index < sizeof(block_map) && block_map[block_index] == 1) {
        block_map[block_index] = 0; // Mark block as free
        ++block_index;
    }
}

// Simple test
int main() {
    memory_init();

    void *ptr1 = memory_alloc(32);
    printf("Allocated 32 bytes at %p\n", ptr1);

    void *ptr2 = memory_alloc(16);
    printf("Allocated 16 bytes at %p\n", ptr2);

    memory_free(ptr1);
    printf("Freed 32 bytes at %p\n", ptr1);

    void *ptr3 = memory_alloc(16);
    printf("Allocated 16 bytes at %p\n", ptr3); // Should reuse freed space

    return 0;
}
