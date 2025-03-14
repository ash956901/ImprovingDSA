#include <unordered_map>
using namespace std;

class DLLNode {
public:
    int key, value;
    DLLNode *prev, *next;

    DLLNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLLNode*> cache;
    int capacity, size;
    DLLNode *head, *tail;

    // Add node to the tail (most recently used position)
    void addToTail(DLLNode* node) {
        node->prev = tail;
        node->next = nullptr;
        if (tail) {
            tail->next = node;
        }
        tail = node;
        if (!head) {
            head = node;
        }
    }

    // Remove a node from the DLL
    void removeNode(DLLNode* node) {
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            // node is head
            head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            // node is tail
            tail = node->prev;
        }
    }

    // Move an existing node to the tail
    void moveToTail(DLLNode* node) {
        removeNode(node);
        addToTail(node);
    }

public:
    LRUCache(int capacity)
        : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        DLLNode* node = cache[key];
        // Move the accessed node to the tail (most recently used)
        moveToTail(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update the value and move the node to tail.
            DLLNode* node = cache[key];
            node->value = value;
            moveToTail(node);
        } else {
            // Create a new node.
            DLLNode* newNode = new DLLNode(key, value);

            // If capacity is reached, remove the head node (LRU).
            if (size == capacity) {
                // Remove from cache map.
                cache.erase(head->key);
                // Remove from DLL.
                DLLNode* oldHead = head;
                removeNode(oldHead);
                delete oldHead;
                size--;
            }

            // Add the new node to the DLL and cache.
            addToTail(newNode);
            cache[key] = newNode;
            size++;
        }
    }
};
