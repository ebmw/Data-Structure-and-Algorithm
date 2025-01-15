#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

template <typename T>
class BinaryTree
{
private:
	// To avoid creating node structure and so on
	T data{};
	BinaryTree *left{};
	BinaryTree *right{};

public:
	BinaryTree(T data) : data(data)
	{
	}

	void print_inorder()
	{
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}

	void add(vector<T> values, vector<char> direction)
	{
		assert(values.size() == direction.size());
		BinaryTree *current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < values.size(); ++i)
		{
			if (direction[i] == 'L')
			{
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			}
			else
			{
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
	}
};

int main()
{
	BinaryTree tree(1);
	tree.add({2, 4, 7}, {'L', 'L', 'L'});
	tree.add({2, 4, 8}, {'L', 'L', 'R'});
	tree.add({2, 5, 9}, {'L', 'R', 'R'});
	tree.add({1, 3, 2}, {'R', 'R', 'L'});

	tree.print_inorder();
	cout << "\n hamza yay";
	// 7 4 8 2 5 9 1 1 2 3

	return 0;
}
