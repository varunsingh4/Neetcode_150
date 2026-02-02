class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //core intuition is to use set because it will remove the duplicate elements and then try to find the smallest part of the subsequence then start counting the length from that position
        int maxLen=0;
        set<int>s1(nums.begin(),nums.end());
        for(auto x:s1)
        {
            if(s1.find(x-1)==s1.end())
            {
                int curr=x;
                int length=1;
                 while(s1.find(curr+1)!=s1.end())
                {
                    curr++;
                    length++;
                    
                }
                maxLen=max(maxLen,length);
            }
           
        }
        return maxLen;
       
    }
};
