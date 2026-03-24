class Solution {
public:
    bool isCorrect(TreeNode* p, TreeNode* q){
        if(p== NULL && q == NULL)
        {
            return true;
        }
        if(p == NULL || q == NULL)
        {
            return false;
        }
        if(p->val != q->val)
        {
            return false;
        }
        return isCorrect(p->left,q->right) && isCorrect(p->right,q->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        return isCorrect(root->left,root->right);

        
       
        
        
    }
};
