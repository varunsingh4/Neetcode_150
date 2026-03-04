class Solution {
public:
   
    void dfs(vector<int>& nums,int index,vector<int>&curr,vector<vector<int>>& res)
    { 
        if(index == nums.size())
        {
            res.push_back(nums);
            return;

        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);    
            dfs(nums,index+1,curr,res);
            swap(nums[i],nums[index]);   //backtrack

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;
        int n = nums.size();
        dfs(nums,0,curr,res);
        return res;
        

        

        
    }
};
