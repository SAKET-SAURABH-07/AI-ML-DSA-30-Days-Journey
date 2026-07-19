#include <iostream>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
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

    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int lD = diameterOfBinaryTree(root->left);
        int rD = diameterOfBinaryTree(root->right);
        int cD = height(root->left) + height(root->right);

        return max(max(lD, rD), cD);
    }
};

int main()
{
   

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter = " << obj.diameterOfBinaryTree(root);

    return 0;
}