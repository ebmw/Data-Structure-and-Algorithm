#include <iostream>
#include<vector>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    /* data */
    T data{}; 
    BinaryTree* right{};
    BinaryTree* left{};

public:
    BinaryTree();

    ~BinaryTree();
};

