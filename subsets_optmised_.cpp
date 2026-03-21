class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int>& curr,int index){
        ans.push_back(curr);
       
        for(int i=index;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            solve(nums,ans,curr,i+1);
            curr.pop_back();

        }
        
        


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        if(n == 0)
        {
            return {{}};
        }
        vector<int>curr;
        solve(nums,ans,curr,0);
        return ans;

    
        
    }
};
