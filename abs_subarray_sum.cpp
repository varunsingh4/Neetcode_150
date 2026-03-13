class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int currMax = 0;
        int currMin = 0;

        int Max = 0;
        int Min = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            currMax = max(nums[i], currMax + nums[i]);
            Max = max(Max, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            Min = min(Min, currMin);
        }

        return max(abs(Max), abs(Min));
    }
};
