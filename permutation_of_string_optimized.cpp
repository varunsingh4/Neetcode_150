class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // take 2 frequency vectors for this question then add all the frequency of chars in vector and then maintain window of the size pf the s1 as soon as the size of the window exceeds than the previous one then remove from the leftmost character freq break as soon as the freq of both the vectors are same
       vector<int>freq1(26,0);
       vector<int>freq2(26,0);
       for(int i=0;i<s1.size();i++)
       {
        freq1[s1[i]-'a']++;
       }
       int left=0;
       for(int right=0;right<s2.size();right++)
       {
            freq2[s2[right]-'a']++;
            if(right-left+1 > s1.size())
            {
                freq2[s2[left]-'a']--;
                left++;

            }
            if(freq1 == freq2)
            {
                return true;
            }

       }
       return false;

         
        
    }
};
