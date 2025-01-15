#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template<typename T>
class AvlTree
{
private:
    /* data */
    T data;
    int bf;
    AvlTree * right;
    AvlTree* left;

    /*
    Alerts
    Queries
    TODOs
    Highlights
    Commented out code can also be styled to make it clear the code shouldn't be there
    Using better comment extension:
    !Alert
    ?Queries
    todo:  a to do thing
    //here 
    *cout<< "hello world"<<endl;
    */
   
    
public:
    /*
    todo:Height function : function that calculates the height
    todo:Height function : function that calculates the height
        todo :input validation 
    //filter /products 


    
    */
     AvlTree(T value):
         data(value),
         bf(0){}
         
    void inorder_print (){
        if (left) 
            left->inorder_print()
        cout << " "<< data << " ";
        if (right)
            right->inorder_print();

    }
    void insert (vector& <T> values ,vector& <char> directions){
        assert(values.size()==directions.size());
        AvlTree* current = this;
        //iterate the path and create all the node with the links between them 

    }
};


