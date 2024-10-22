#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LRUCache {
    int capacity;
    int size;
    Node** hashTable;  // Hash table for fast lookup
    Node* head;        // Most recently used
    Node* tail;        // Least recently used
} LRUCache;

#define HASH_SIZE 1000  // Arbitrary large hash size for quick lookup

// Helper function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Initialize the LRU Cache
LRUCache* lruCacheCreate(int capacity) {
    printf("create LRU Cache\n");
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->hashTable = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    cache->head = cache->tail = NULL;
    return cache;
}

// Move a node to the front (MRU position)
void moveToHead(LRUCache* cache, Node* node) {
    printf("move head to front\n");
    if (cache->head == node) return;  // Already at head

    // Remove the node from its current position
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (node == cache->tail) cache->tail = node->prev;

    // Move the node to the head
    node->prev = NULL;
    node->next = cache->head;
    if (cache->head) cache->head->prev = node;
    cache->head = node;

    if (!cache->tail) cache->tail = node;  // Handle empty list case
}

// Remove the least recently used node (tail)
void removeTail(LRUCache* cache) {
    printf("remove tail\n");
    if (!cache->tail) return;

    Node* node = cache->tail;
    if (node->prev) node->prev->next = NULL;
    else cache->head = NULL;  // Cache becomes empty

    cache->tail = node->prev;
    cache->hashTable[node->key % HASH_SIZE] = NULL;  // Remove from hash table
    free(node);
    cache->size--;
}

// Get the value of a key from the cache
int lruCacheGet(LRUCache* cache, int key) {
    printf("get value of a key from cache\n");
    Node* node = cache->hashTable[key % HASH_SIZE];
    if (!node) return -1;  // Key not found

    // Move the accessed node to the front (MRU position)
    moveToHead(cache, node);
    return node->value;
}

// Put a key-value pair into the cache
void lruCachePut(LRUCache* cache, int key, int value) {
    Node* node = cache->hashTable[key % HASH_SIZE];

    if (node) {  // Key already exists, update the value
        node->value = value;
        moveToHead(cache, node);
    } else {  // New key, insert into the cache
        if (cache->size == cache->capacity) {
            removeTail(cache);  // Evict the least recently used node
        }

        // Create a new node and add it to the head
        Node* newNode = createNode(key, value);
        newNode->next = cache->head;
        if (cache->head) cache->head->prev = newNode;
        cache->head = newNode;

        if (!cache->tail) cache->tail = newNode;  // First node in the cache

        cache->hashTable[key % HASH_SIZE] = newNode;  // Store in hash table
        cache->size++;
    }
}

// Free the entire cache
void lruCacheFree(LRUCache* cache) {
    Node* current = cache->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(cache->hashTable);
    free(cache);
}

// Testing the LRU Cache
int main() {
    LRUCache* cache = lruCacheCreate(2);

    lruCachePut(cache, 1, 1);
    lruCachePut(cache, 2, 2);
    printf("Get 1: %d\n", lruCacheGet(cache, 1));  // Returns 1

    lruCachePut(cache, 3, 3);  // Evicts key 2
    printf("Get 2: %d\n", lruCacheGet(cache, 2));  // Returns -1 (not found)

    lruCachePut(cache, 4, 4);  // Evicts key 1
    printf("Get 1: %d\n", lruCacheGet(cache, 1));  // Returns -1 (not found)
    printf("Get 3: %d\n", lruCacheGet(cache, 3));  // Returns 3
    printf("Get 4: %d\n", lruCacheGet(cache, 4));  // Returns 4

    lruCacheFree(cache);
    return 0;
}
