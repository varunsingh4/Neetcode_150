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
    TreeNode* invertTree(TreeNode* root) {
        if(root ==NULL)
        {
            return  NULL;
        }
        TreeNode*temp=root->right;    // save the original node because if you swap after then it will place the updated right on the left as well so saving is very important
        root->right=invertTree(root->left);
        root->left=invertTree(temp);
        return root;
        
    }
};
