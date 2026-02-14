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

        if(root == NULL)
        {
            return true;
        }
        if(abs(calcMaxHeight(root->left)-calcMaxHeight(root->right))>1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};
