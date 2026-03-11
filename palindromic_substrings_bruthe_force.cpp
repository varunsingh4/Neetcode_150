class Solution {
public:
    bool isValidPalindrome(string s,int start,int end)
    {
        int i=0;
        while(start < end && i <s.size())
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;

    }
    string solve(string s,int start,int end){
        int n = s.size();
        int start_index=0;
        int max_len=1;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<n;j++)
            {
                string k = s.substr(i,j-i+1);
                if(isValidPalindrome(k,0,k.size()-1)){
                    if(j-i+1 > max_len){
                        max_len=j-i+1;
                        start_index=i;
                    }

                }

            } 

        }
        return s.substr(start_index,max_len);
        
    }
    string longestPalindrome(string s) {
        int start=0;
        int end=0;
        string ans=solve(s,start,end);
        return ans;

        
        
        
    }
};
