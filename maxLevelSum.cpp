class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q1;
        q1.push(root);
        vector<int>level;
        while(!q1.empty())
        {
            int size = q1.size();
            int sum=0;
            for(int i = 0;i < size ; i++ )
            {
                TreeNode* front = q1.front();
                q1.pop();
                sum = sum+ front->val;
                if( front -> left)
                {
                    q1.push(front -> left);
                }
                if( front -> right)
                {
                    q1.push( front -> right);
                }


            }
            level.push_back(sum);
        }
        int max_ele=INT_MIN;
        int ans=0;
        for(int i=0;i<level.size();i++)
        {
            if(level[i] > max_ele)
            {
                max_ele=level[i];
                ans=i+1;
            }


        }
        return ans;


    }
};
