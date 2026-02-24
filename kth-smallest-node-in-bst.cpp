class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s1;
        TreeNode*curr=root;
        while(curr!=NULL ||  !s1.empty()) 
        {
            while(curr!=NULL)
            {
                s1.push(curr);
                curr=curr->left;
            }
                curr=s1.top();
                s1.pop();
                k--;
            if(k ==0)
            {
                return curr->val;

            }
            curr=curr->right;

        }
        return -1;
        
    }
};
