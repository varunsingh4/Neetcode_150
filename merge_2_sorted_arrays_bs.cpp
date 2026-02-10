class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n)
        {
            return findMedianSortedArrays(nums2,nums1); 
        }

        int lo=0;
        int high=nums1.size();
        int half=(m+n+1)/2;

        int l1=0,l2=0,r1=0,r2=0;
        double ans=0;

        while(lo<=high)
        {
            int i=lo+(high-lo)/2;
            int j=half-i;

            // ---- l1 ----
            if(i==0)
                l1=INT_MIN;
            else
                l1=nums1[i-1];

            // ---- r1 ----
            if(i==m)
                r1=INT_MAX;
            else
                r1=nums1[i];

            // ---- l2 ----
            if(j==0)
                l2=INT_MIN;
            else
                l2=nums2[j-1];

            // ---- r2 ----
            if(j==n)
                r2=INT_MAX;
            else
                r2=nums2[j];

            if(l1 <= r2 && l2 <= r1)
            {
                if((m+n)%2)
                {
                    ans = max(l1,l2);
                }
                else
                {
                    ans = (max(l1,l2) + min(r1,r2)) / 2.0;
                }
                return ans;
            }
            else if(l1 > r2)
            {
                high=i-1;
            }
            else
            {
                lo=i+1;
            }
        }

        return ans;
    }
};
