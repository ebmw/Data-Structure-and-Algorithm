#include <iostream>
using namespace std;
class node
{
public:
    /* data */
    int data;
    node *next;

    node(int value) : data(value), next(nullptr) {};
};
class singly_linked_list
{
private:
    /* data */
    node *head;

public:
    singly_linked_list(/* args */)
    {
        head = new node(0);
    };

    // return the size of the linked list
    int size()
    {
        int count = 0;
        node *current = head->next;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    // print the linked list
    void printLinkedList() const
    {
        node *temp = head;
        while (temp->next)
        {
            /* code */
            cout << temp->data << " --> ";
        }
        cout << " -- > " << " nullptr" << endl;
    }
    // test if a value x is contained in the linked list
    bool containt(int x)
    {
        node *temp = head;
        while (temp->next)
        {
            if (temp->data == x)
                return false;
        }
        return true;
    }
    // add a value x at the beginning of the list if it is not already contained in the linked list
    bool addbeginning(int value)
    {
        if (containt(value))
            return false;
        node *temp = new node(value);
        temp->next = head;
        head = temp;
        return true;
    }
    // add a value x at the end of the list if it is not already contained in the linked list
    bool addend(int value)
    {
        if (containt(value))
            return false;
        node *newnode = new node(value);
        node *temp = head;
        while (temp->next)
        {
            /* code */
            temp = temp->next;
        }
        temp->next = newnode;
    }
    // remove the first occurrence of a value x if x is contained in the linked list
    bool remove(int value)
    {
        if (!containt(value))
            return false;
        node *temp = head;
        while (temp->next)
        {
            if (temp->next->data == value)
            {
                node *toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return true;
            }
        }
    }
    ~singly_linked_list()
    {
        node *current = head;
        while (current)
        {
            node *toDelete = current;
            current = current->next;
            delete toDelete;
        }
    };

};
