class Solution {
public:
    int findMin(vector<int>& nums) {
        //key intuition is to find the sorted part of array and search in that the minimum element in the unosrted party
        //In a rotated sorted array (no duplicates), the minimum is always in the half that contains the rotation point.
        //In a rotated sorted array, one half is always sorted.
//I compare nums[mid] with nums[high] to figure out whether the rotation point — which is the minimum — lies to the left or right of mid.”
//And you can detect which half that is by comparing nums[mid] with nums[high].

//if right side is sorted and we 
        int low=0;
        int high=nums.size()-1;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[high] >= nums[mid]) //can be a case when array is left is sorted and minimum point lies in left so comparision between high and mid only works here
            {
                
                    high=mid;
            }

                else 
                {
                    low=mid+1;
                    
                }
        }
        return nums[low];

        
    }
};
