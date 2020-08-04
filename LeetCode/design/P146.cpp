#include <unordered_map>

class Node {
    public:
        int key;
        int data;
        Node *prev;
        Node *next;
    /**
     * Class representation of doubly linked list
     *
     * @param[in] key_val: Key value
     * @param[in] data_val: Data value
     * @param[in] prev_node: A pointer to the previous node
     * @param[in] next_node: A pointer to the next node
     */
    Node(int key_val, int data_val, Node *prev_node, Node *next_node) {
        key = key_val;
        data = data_val;
        prev = prev_node;
        next = next_node;
    }
};

class LRUCache {
public:
    int cache_size;
    std::unordered_map<int, Node*> items;
    Node *head;
    Node *tail;

    /**
     * Problem from LeetCode 146: LRU Cache. You can find the
     * problem
     * <a href="https://leetcode.com/problems/lru-cache/">
     * here</a>.
     *
     * @param[in] capacity: Capacity of LRU cache
     */
    LRUCache(int capacity) {
        cache_size = capacity;
        head = new Node(0, 0, NULL, NULL);
        tail = head;
    }
    
    /**
     * Get the value (will always be positive) of the key
     *
     * @param[in] key: Key
     * @returns If the key exists in the cache, otherwise return -1.
     */
    int get(int key) {
        int value;

        if (items.count(key)) {
            Node *node = items[key];
            value = node->data;
            if (node != head) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->prev = head;
                head->next = node;
                head = head->next;   
            }
        } else {
            value = -1;
        }
        return value;
    }

    /**
     * Set or insert the value if the key is not already present. When the
     * cache reached its capacity, it should invalidate the least recently used
     * item before inserting a new item.
     *
     * @param[in] key: Key
     * @param[in] value: Value
     */
    void put(int key, int value) {
        if (items.count(key)) {
            Node *node = items[key];
            node->data = value;
            if (node != head) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->prev = head;
                head->next = node;
                head = head->next;
            }
        } else {
            if (items.size() == cache_size) {
                Node *last_node = tail->next;
                items.erase(last_node->key);
                tail->next = last_node->next;
                if (last_node->next) {
                    last_node->next->prev = tail;
                }
            }
            Node *node = new Node(key, value, NULL, NULL);
            node->prev = head;
            head->next = node;
            head = head->next;
            items[key] = node;
        }
    }
};

int main(int argc, char const *argv[]) {
    LRUCache *lru_cache = new LRUCache(2);

    lru_cache->put(1, 1);
    lru_cache->put(2, 2);
    assert(lru_cache->get(1) == 1);
    lru_cache->put(3, 3);
    assert(lru_cache->get(2) == -1);
    lru_cache->put(4, 4);
    assert(lru_cache->get(1) == -1);
    assert(lru_cache->get(3) == 3);
    assert(lru_cache->get(4) == 4);

    return 0;
}
