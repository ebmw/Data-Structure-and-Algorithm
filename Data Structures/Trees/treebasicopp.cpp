#include <iostream>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    node(int val) : value(val), left(nullptr), right(nullptr) {}
};

int countNodes(node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int countFullNodes(node* root) {
    if (root == nullptr) return 0;
    int isFull = (root->left != nullptr && root->right != nullptr) ? 1 : 0;
    return isFull + countFullNodes(root->left) + countFullNodes(root->right);
}

int computeDepth(node* root) {
    if (root == nullptr) return -1;
    if(!(root->left && root->right))return 0;
    return 1 + max(computeDepth(root->left), computeDepth(root->right));
}

void printElements(node* root) {
    if (root == nullptr) return;
    printElements(root->left);
    cout << root->value << " ";
    printElements(root->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    cout << "Number of nodes: " << countNodes(root) << endl;
    cout << "Number of leaves: " << countLeaves(root) << endl;
    cout << "Number of full nodes: " << countFullNodes(root) << endl;
    cout << "Depth of the tree: " << computeDepth(root) << endl;

    cout << "Elements in the tree: ";
    printElements(root);
    cout << endl;

    return 0;
}
