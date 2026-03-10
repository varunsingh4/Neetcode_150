class Solution {
    vector<vector<int>>res;
    vector<vector<int>>curr;
public:
    void dfs(vector<int>& nums,int index){
        if(nums.size()-1 == index)
        {
            res.push_back(nums);
            return ;

        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            dfs(nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index=0;
        dfs(nums,0);
        return res;
       
    }
    
};
