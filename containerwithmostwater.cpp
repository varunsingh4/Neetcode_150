class Solution {
public:
    int maxArea(vector<int>& height) {
         //core intuition is to use 2 pointers for measuring height of left and right pointers and then keep on finding the next larger height so that we can get max area when height of left is higher decrement right since we need to find the next right which can give more water
        int area=0;
        int low=0;
        int maxArea=INT_MIN;
        int high=height.size()-1;
        while(low<=high)
        {
            area=high-low;
            maxArea=max(maxArea,area*min(height[high],height[low]));
            height[low]>=height[high]? high--:low++;
            
        }
        return maxArea;
    }
};
```
