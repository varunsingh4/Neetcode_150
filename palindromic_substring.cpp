class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int left=0;
        int right=0;
        int maxLen=0;
        int start=0;
        
        for(int c=0;c<n;c++)
        {
            left=c;
            right=c;
            while(left >=0 && s[left] == s[right] )
            {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
            left=c+1;
            right=c;
            while(left >=0 && s[left] == s[right])
            {
                    if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }

        }
        return s.substr(start,maxLen);
        
    }
};
