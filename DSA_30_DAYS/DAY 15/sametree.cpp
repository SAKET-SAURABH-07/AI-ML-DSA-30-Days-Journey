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

bool isSameTree(Node* p, Node* q)
{
    // Both nodes are NULL
    if(p == NULL && q == NULL)
    {
        return true;
    }

    // One node is NULL
    if(p == NULL || q == NULL)
    {
        return false;
    }

    // Data is different
    if(p->data != q->data)
    {
        return false;
    }

    // Compare left and right subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main()
{
    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if(isSameTree(root1, root2))
    {
        cout << "Trees are Same";
    }
    else
    {
        cout << "Trees are Different";
    }

    return 0;
}