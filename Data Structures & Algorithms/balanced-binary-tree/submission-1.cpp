/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool flag=false;
    int height(TreeNode * node){
    if(!node){
        return 0;
    }
    return 1+max(height(node->left),height(node->right));

    }

    bool isBalanced(TreeNode* root) {
         if(!root){
        return true;
    }
        int height1=height(root->left);
        
        int height2=height(root->right);

     if(abs(height1-height2)>1){
            return false;
    }

        return abs(height1-height2)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};



