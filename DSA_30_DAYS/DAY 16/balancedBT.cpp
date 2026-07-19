#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        int diff = abs(lh - rh);

        if(diff > 1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{
    /*
            1
           / \
          2   3
         / \
        4   5

        Balanced Tree
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if(obj.isBalanced(root))
        cout << "Tree is Balanced";
    else
        cout << "Tree is Not Balanced";

    return 0;
}