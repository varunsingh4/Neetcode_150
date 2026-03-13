class Solution {
public:
    int solve(vector<int>& nums,int index,int max_sum){
        if(index == 0)
        {
            return nums[0];
        }
        int prev=solve(nums,index-1,max_sum);
        return max(nums[index],nums[index]+prev);            
    }
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int a =nums[0];
        for(int i=0;i<nums.size();i++)
        {
            a=max(a,solve(nums,i,max_sum));
        }
        return a;
        
    }
};
