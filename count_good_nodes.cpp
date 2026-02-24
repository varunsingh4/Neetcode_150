 // Intuition:
// My initial thought was correct: a node is "good" if its value is greater than or
// equal to the maximum value seen so far on the path from the root to that node.
// To solve this, I track the maximum value while traversing the tree using DFS.
//
// Initial mistake:
// I first treated the maximum value as a global across the entire tree, which is incorrect.
// The condition depends on the path from the root to the current node, not on other branches.
// Because of this, updates made while exploring one subtree affected sibling subtrees.
//
// Correct approach:
// Before updating the current maximum, I store the previous path maximum (prevMax).
// After finishing recursion on the left and right children, I restore the previous maximum.
// This ensures each root-to-node path maintains its own maximum value.
//
// Key idea:
// Path-specific state must be preserved during recursion; global state must be restored
// when backtracking.
class Solution {
public:
int max_=INT_MIN;
int count=0;
    int goodNodes(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int prev_max=max_;
        if(root->val >= max_)
        {
            max_=root->val;
            count++;
        }
        goodNodes(root->left);
        goodNodes(root->right);
        max_=prev_max;

        return count;
    }
};
