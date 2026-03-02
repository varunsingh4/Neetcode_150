class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case: if node is NULL, nothing found in this path
        if(root == NULL)
        {
            return NULL;
        }

        // Recursively search for p and q in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Recursively search for p and q in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If the current node itself is p or q,
        // we return it upward because it could be the LCA
        if(root == p || root == q)
        {
            return root;
        }

        // If left subtree didn't find anything,
        // answer must be in the right subtree
        if(left == NULL)
        {
            return right;
        }

        // If right subtree didn't find anything,
        // answer must be in the left subtree
        else if(right == NULL)
        {
            return left;
        }

        // If both left and right returned non-NULL,
        // that means p was found in one side
        // and q was found in the other side
        // so the current node is the Lowest Common Ancestor
        else{
            return root;
        }
        
    }
};
