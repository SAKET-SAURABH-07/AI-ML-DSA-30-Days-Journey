#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxDepth(Node* root)
{
    // Base Case
    if(root == NULL)
    {
        return 0;
    }

    // Recursive Calls
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    // Return Maximum Height
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    /*
            1
           / \
          2   3
         / \
        4   5
             \
              6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->right = new Node(6);

    cout << "Maximum Depth = " << maxDepth(root);

    return 0;
}