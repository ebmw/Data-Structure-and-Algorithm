#ifndef SIMPLE_HASH_TABLE_H
#define SIMPLE_HASH_TABLE_H

#include <vector>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

int nextPrime(int n);

template <typename T>
class SimpleHashTable {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    vector<Node*> table; 
    int size;            

    size_t hash(const T& key) const {
        static hash<T> hasher;
        return hasher(key) % table.size();
    }

    void clear() {
        for (auto& head : table) {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    void rehash() {
        vector<Node*> oldTable = table;
        table.resize(nextPrime(2 * table.size()), nullptr);
        size = 0;

        for (auto head : oldTable) {
            while (head) {
                add(std::move(head->value));
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

public:
    SimpleHashTable(int capacity = 101) : size(0) {
        table.resize(capacity, nullptr);
    }

    ~SimpleHashTable() {
        clear();
    }

    bool contains(const T& key) const {
        Node* head = table[hash(key)];
        while (head) {
            if (head->value == key) return true;
            head = head->next;
        }
        return false;
    }

    bool add(const T& key) {
        size_t index = hash(key);
        Node* head = table[index];

        for (Node* node = head; node; node = node->next) {
            if (node->value == key) return false; 
        }

        table[index] = new Node(key, table[index]);
        if (++size > table.size()) rehash();
        return true;
    }

    bool add(T&& key) {
        size_t index = hash(key);
        Node* head = table[index];

        for (Node* node = head; node; node = node->next) {
            if (node->value == key) return false; 
        }

        table[index] = new Node(std::move(key), table[index]);
        if (++size > table.size()) rehash();
        return true;
    }

    bool remove(const T& key) {
        size_t index = hash(key);
        Node*& head = table[index];

        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            if (curr->value == key) {
                if (prev) prev->next = curr->next;
                else head = curr->next;

                delete curr;
                --size;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }

        return false;
    }

    void clearAll() {
        clear();
        size = 0;
    }
};

#endif


/*



. Data Structures Used
Vector of Lists
 Functions:
find 
hash 
2. Insert and Delete Operations
Insert Operation:
The hash function
The specific list at the computed index is checked for the presence of the element using find
If the element is absent, it is added to the end of the list using push_back
After insertion, the currentSize is incremented. If the number of elements exceeds the size of the table, rehashing is used
Delete Operation:
The hash function determines the appropriate list
If the element exists in the list, it is erased using erase
The currentSize is decremented
3. Rehashing
Purpose: Rehashing ensures that the hash table maintains good performance by keeping the load factor (number of elements per bucket) low
Implementation:
A new hash table is created with a size equal to the next prime number greater than twice the current table size
All elements from the old hash table are reinserted into the new hash table using the insert method
The move operation is used to transfer elements efficiently


*/  