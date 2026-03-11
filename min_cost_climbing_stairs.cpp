class Solution {
public:
    int solve(vector<int>& cost,int n,int start,vector<int>&dp){
        if(start == n-1 )
        {
            return cost[n-1];
        }
        if(start ==  n-2)
        {
            return cost[n-2];
        }
        if(dp[start]!=-1)
        {
            return dp[start];   //changing state is start so we have index as start
        }
        int ans1=cost[start]+solve(cost,n,start+1,dp);
        int ans2=cost[start]+solve(cost,n,start+2,dp);
        return dp[start]=min(ans1,ans2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        
        int a=solve(cost,n,0,dp);
        int b= solve(cost,n,1,dp);
        return min(a,b);
        
    }
};
