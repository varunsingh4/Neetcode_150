class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;
        vector<int>ans;
        int max_=INT_MIN;
        int i=0;
        for(int right=0;right<nums.size();right++)
        {
            max_=max(max_,nums[right]);
            if(right - left+1 ==k)
            {
                int max_=nums[left];
                 for (int i = left; i <= right; i++) {
                    max_ = max(max_, nums[i]);
                }

                ans.push_back(max_);
                left++;

            }

        }
        return ans;
        
    }
};
