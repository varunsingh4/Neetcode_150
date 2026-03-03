class Solution {
public:
   int sum = 0;

    void dfs(vector<int>& candidates, int target, int index, int endIndex,
             vector<int>& curr, vector<vector<int>>& res) {

        if (sum == target) {
            res.push_back(curr);
            return;
        }
        if (sum > target) return;

        for (int i = index; i < endIndex; i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (sum + candidates[i] > target) break; // sorted pruning (optional but good)

            curr.push_back(candidates[i]);
            sum += candidates[i];

            dfs(candidates, target, i + 1, endIndex, curr, res); // i+1 (use once)

            sum -= candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index=0;
        int endIndex=0;
        vector<int>curr;
        vector<vector<int>>res;
        for(int i=0;i<candidates.size();i++)
        {
            if(candidates[i] > target)
            {
                endIndex=i;
                break;

            }
        }
        dfs(candidates,target,index,endIndex,curr,res);
        return res;

        
    }
};
