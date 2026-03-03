class Solution {
public:
    void backtracking(vector<int>& nums,vector<int>&curr,vector<vector<int>>& res,int index){
        res.push_back(curr);
        for(int i=index;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            backtracking(nums,curr,res,index+1);
            curr.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;
        backtracking(nums,curr,res,0);
        return res;


        
    }
};
