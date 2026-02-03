class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1;
        for(int i=0;i<s1.size();i++)
        {
            m1[s1[i]]++;

        }
        unordered_map<char,int>m2;
        vector<int>ans;
        int left=0;
        for(int right=0;right<s2.size();right++)
        {
            if(!m1.count(s2[right]))
            {
                continue;
            }
            else{
                m2.clear();
                left=right;
                
                while(right-left+1 <= s1.size() && m1.count(s2[right]))
                {
                    m2[s2[right]]++;
                    right++;
                }
                if(m1 == m2)
                {
                    return true;
                }
                right=left;
            }
        }
        
        return false;
        
        
        

         
        
    }
};
