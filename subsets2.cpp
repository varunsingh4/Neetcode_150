class Solution {
public:
    vector<vector<int>>res;
    vector<int>curr;
    void subsets(vector<int>& nums,int index,vector<vector<int>>& res,vector<int>& curr){
        res.push_back(curr);
        for(int i=index;i<nums.size();i++)
        {
            if (i > index && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            subsets(nums,i+1,res,curr);
            curr.pop_back();

        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        subsets(nums,0,res,curr);
        return res;


        
    }
};
