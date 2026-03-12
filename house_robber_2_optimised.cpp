class Solution {
public:
    int maxMoney(vector<int>& nums,int startindex,int endIndex,int n,vector<int>&dp){
         if (startindex > endIndex) {
            return 0;
        }
        if(startindex == endIndex)
        {
            return nums[endIndex];
        }
        if(dp[startindex]!=-1)
        {
            return dp[startindex];

        }
        int included=nums[startindex]+maxMoney(nums,startindex+2,endIndex, n,dp);
        int excluded=maxMoney(nums,startindex+1,endIndex,n,dp);
        return dp[startindex]=max(included,excluded);
        

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int index=0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int a=maxMoney(nums,0,n-2,n,dp1);
        int b=maxMoney(nums,1,n-1,n,dp2);
        return max(a,b);

        
    }
};
