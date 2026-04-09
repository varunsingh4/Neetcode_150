class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
         if( root == NULL)
        {
            return{};
        }
        vector<int>ans;
        vector<int>level;
        int max_ = INT_MIN ;
        queue<TreeNode*>q1;
        q1.push(root);
        while( !q1.empty())
        {
            int size = q1.size();
            max_=INT_MIN;
            
            level.clear();
            
            for(int i = 0 ; i < size ;i++)
            {
                TreeNode* front  =  q1.front();
                q1.pop();
                level.push_back(front->val);
                if( front->left)
                {
                    q1.push(front->left);
                }
                if( front->right)
                {
                    q1.push(front->right);
                }
            }
            for(int i = 0 ;  i < level.size(); i++)
            {
               max_ = max(max_,level[i]);
            }
            ans.push_back(max_);
        }
        return ans;
        
        
    }
};
