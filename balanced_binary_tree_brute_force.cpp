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
    int calcMaxHeight(TreeNode* root){
        if(root == NULL)
        {
            return 0;
        }
        int leftHeight=calcMaxHeight(root->left);
        int rightHeight=calcMaxHeight(root->right);
        return 1+max(leftHeight,rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        //intuition is that you have to check for each right anf left subtree at root and also to check the subtree below it u have to check for the overall tree //time_complexity is o(n2)

        if(root == NULL)
        {
            return true;
        }
        if(abs(calcMaxHeight(root->left)-calcMaxHeight(root->right))>1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right); //checking for smaller subtrees too there might be cases where they are balanced 
        
    }
};
