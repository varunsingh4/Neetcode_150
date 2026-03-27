class Solution {
public:
    int calcHeight(TreeNode*root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftHeight = calcHeight(root->left);
        int rightHeight = calcHeight(root->right);
        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        if(abs(calcHeight(root->left)-calcHeight(root->right)) > 1 )
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};
