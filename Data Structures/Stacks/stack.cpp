#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class stack
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T value, Node *nextptr = nullptr) : data(value), next(nextptr) {}
    };

    Node *topnode;

public:
    stack() : topnode(nullptr) {}
    
    bool isEmpty() const { return topnode == nullptr; }
    
    T top() const
    {
        if (isEmpty())
            assert(false && "Stack Is Empty");
        return topnode->data;
    }
    
    void Push(T value)
    {
        topnode = new Node(value, topnode);
    }
    
    T pop()
    {
        if (isEmpty())
            assert(false && "Stack Is Empty");
            
        Node *tempnode = topnode;
        topnode = topnode->next;

        T data = tempnode->data;
        delete tempnode;
        return data;
    }
    
    ~stack()
    {
        while (!isEmpty())
            pop();
    }
};
// #include <iostream>
// using namespace std;
// template <typename T>
// class Stack {
// private:
//     struct Node {
//         T data;
//         Node *next;
//         Node(const T &data, Node *next = nullptr) : data(data), next(next) {}
//     };

//     Node *topNode;

// public:
//     Stack() : topNode(nullptr) {}

//     bool isEmpty() const { return topNode == nullptr; }

//     void push(const T &x) {
//         topNode = new Node(x, topNode);
//     }

//     void pop() {
//         if (isEmpty()) return;
//         Node *oldTop = topNode;
//         topNode = topNode->next;
//         delete oldTop;
//     }

//     T top() const {
//         if (isEmpty()) cout << ("Stack is empty");
//         return topNode->data;
//     }

//     ~Stack() {
//         while (!isEmpty()) pop();
//     }
// };

