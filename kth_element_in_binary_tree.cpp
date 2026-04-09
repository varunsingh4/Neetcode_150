class Solution {
public:
    vector<int> ans ; 
    void  inorder (TreeNode* root , int k  ){
        if(root == NULL)
        {
            return ; 
        }
        inorder(root->left , k);
        ans.push_back(root->val);
        inorder(root->right , k);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root , k);
        return ans[k-1];
            
    }
};
