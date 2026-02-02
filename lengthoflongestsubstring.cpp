class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_set<char>s1;
        int max_len=0;
        for(int right=0;right<s.size();right++)
        {
            while(s1.find(s[right])!=s1.end())
            {
                s1.erase(s[left]);
                left++;

            }
            max_len=max(max_len,right-left+1);
            s1.insert(s[right]);
           

        }
        return max_len;
        
    }
};
