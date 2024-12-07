#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T &data, Node *next = nullptr) : data(data), next(next) {}
    };

    Node *frontNode;
    Node *backNode;

public:
    Queue() : frontNode(nullptr), backNode(nullptr) {}

    bool isEmpty() const { return frontNode == nullptr; }

    void enqueue(const T &x) {
        Node *newNode = new Node(x);
        if (isEmpty()) {
            frontNode = backNode = newNode;
        } else {
            backNode->next = newNode;
            backNode = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) return;
        Node *oldFront = frontNode;
        frontNode = frontNode->next;
        delete oldFront;
        if (frontNode == nullptr) backNode = nullptr; // Queue is now empty
    }

    T front() const {
        if (isEmpty()) cout <<("Queue is empty");
        return frontNode->data;
    } 

    ~Queue() {
        while (!isEmpty()) dequeue();
    }
};
