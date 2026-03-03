class Solution {
public:
    vector<int>curr;
    vector<vector<int>>res;
    int sum=0;
    void dfs(vector<int>& candidates, int target,int startIndex,int endIndex,vector<int>&curr,vector<vector<int>>& res)
    {
        if(sum == target)
        {
            res.push_back(curr);
            return;
        }
        if(sum > target)
        {
            return;
        }
        for(int i=startIndex;i<endIndex;i++){
            if(i > startIndex && candidates[i] == candidates[i-1])
            {
                continue;
            }
            curr.push_back(candidates[i]);
            sum+=candidates[i];
            dfs(candidates,target,i+1,endIndex,curr,res);  //doing i+1 so that we are not picking the same element again
            sum-=candidates[i];
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int startIndex=0;
        int endIndex=candidates.size();
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++)
        {
            if(candidates[i] > target)
            {
                endIndex=i;
                break;
            }
        }
        dfs(candidates,target,startIndex,endIndex,curr,res);
        return res;
        

    }
};
