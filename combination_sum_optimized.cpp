class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> & ans,vector<int> &curr,int index,int endIndex){
        if(target == 0)
        {
            ans.push_back(curr);
        }
        if(target < 0)
        {
            return;
        }
      

        for(int i=index;i<endIndex;i++)
        {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            target=target-candidates[i];

            solve(candidates,target,ans,curr,i+1,endIndex);
            target=target+candidates[i];
            curr.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int endIndex=candidates.size();
        for(int i=0;i<candidates.size();i++)
        {
            if(candidates[i] > target)
            {
                endIndex=i;
                break;
            }
        }
        vector<vector<int>>ans;
        vector<int>curr;
        int index=0;
        solve(candidates,target,ans,curr,index,endIndex);
        return ans;


        
    }
};
