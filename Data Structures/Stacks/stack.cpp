#include <iostream>
using namespace std; 
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T &data, Node *next = nullptr) : data(data), next(next) {}
    };

    Node *topNode;

public:
    Stack() : topNode(nullptr) {}
    
    bool isEmpty() const { return topNode == nullptr; }

    void push(const T &x) {
        topNode = new Node(x, topNode);
    }

    void pop() {
        if (isEmpty()) return;
        Node *oldTop = topNode;
        topNode = topNode->next;
        delete oldTop;
    }

    T top() const {
        if (isEmpty()) cout << ("Stack is empty");
        return topNode->data;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};
