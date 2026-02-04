class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int right=0;
        dequeue<int>dq;
        for(int i=0;i<nums.size();i++)
        {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.front()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)
            {
                nums.push_back(nums[dq.front()]);
            }
        }
        
    }
};
