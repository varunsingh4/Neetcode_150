class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s1;
        int n = temperatures.size();  // we are using stack to store the number of days which are less warmer than the current pointer days so for eg[75,74]. we are storing the stack in decreasing order
        vector<int>ans(n,0);
        for(int i=0;i<temperatures.size();i++)
        {
            while(!s1.empty() &&temperatures[s1.top()] < temperatures[i])//using while not if since we need to check if all the elements that are smaller than the current one
            {
                int prev=s1.top();
                s1.pop();
                int curr=i-prev;
                ans[prev]=curr;
            }
            s1.push(i);

        }
        return ans;

        
    }
};
