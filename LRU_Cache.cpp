#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    int cache_capacity;
    list<int> lru_list;  // To track the order of usage of keys
    unordered_map<int, pair<int, list<int>::iterator>> cache_map; // key -> (value, iterator to list)

    LRUCache(int capacity) : cache_capacity(capacity) {}

    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            cout << "get key does not exist\n";
            return -1; // Key not found
        } else {
            // Move the accessed key to the front of the list (most recently used)
            lru_list.erase(cache_map[key].second);
            lru_list.push_front(key);
            cache_map[key].second = lru_list.begin();
            return cache_map[key].first; // Return the value associated with the key
        }
    }

    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end())
        {
            cout << "key found .. update value and move to front\n";
            // Key exists, update the value and move the key to the front (MRU)
            lru_list.erase(cache_map[key].second);
            lru_list.push_front(key);
            cache_map[key] = {value, lru_list.begin()};
        }
        else 
        {
            cout << "key does not exist\n";
            // Key doesn't exist
            if (lru_list.size() == cache_capacity) {
                // Cache is full, remove the least recently used (LRU) key
                int lru_key = lru_list.back();
                lru_list.pop_back();
                cache_map.erase(lru_key);
            }
            // Insert the new key-value pair
            lru_list.push_front(key);
            cache_map[key] = {value, lru_list.begin()};
        }
    }
};


int main()
{
    LRUCache cache = LRUCache(2);

cout <<" main .. \n";
cache.put(1, 2);
cout << "get = "<< cache.get(1) << "\n";
cache.put(1, 3);
cache.put(2, 4);
cout << "get = "<< cache.get(2) << "\n";

return 0;
}