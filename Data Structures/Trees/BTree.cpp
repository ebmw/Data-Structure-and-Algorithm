#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    /* data */
    T data{};
    BinaryTree *right{};
    BinaryTree *left{};

public:
    BinaryTree(T Data) : data(Data) {};
    void print_inorder(){
        if(left) print_inorder(left);
        cout << data <<" ";
        if (right) print_inorder(right)

    }
    void add(const vector <int>& Data , const vector <char>& directions ){
        BinaryTree* current = this;
        for (int i =0 ; i < data.size() ; i++){
            if ("L" == directions[i]){
                if(!left) 
                    current->left= new BinaryTree(data[i]),
                    current= current->left;
            }
        }
    }





    

    ~BinaryTree();
};
