#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std ;

struct node
{
    /* data */
    int data{};
    node *right{};
    node *left{};
    node(int d) : data(d) {};
};

int treeSize()
{
    srand(time(0));
    // j = i + rand() % (vec.size() - i);
    int lower = 1;

    int randomNum = lower + (rand() % (100));
}



node* insertBT(node *root, int key)
{
    if (!root)
    {
        return new node(key);
    }
    if (key < root->data)
    {
        root->left = insertBT(root->left, key);
    }
    else
    {
        root->right = insertBT(root->right, key);
    }
    return root;
}

void shuffleVector(vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        size_t j = i + rand() % (vec.size() - i);
        swap(vec[i], vec[j]);
    }
}

node* generateRandomBSTNumbers(int N)
{
    srand(time(0));
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        numbers[i] = i + 1;

        shuffleVector(numbers);

        node *root = nullptr;
        for (int key : numbers)
        {
            root = insertBT(root, key);
        }
        return root;
    }
}
void inorderTraversal(node *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    srand(time(0)); // Seed the random number generator

    int n = 10; // Number of nodes
    node *bstRoot = generateRandomBSTNumbers(n);

    cout << "In-order traversal of the BST: ";
    inorderTraversal(bstRoot);
    cout << endl;

    return 0;
}