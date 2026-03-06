class Solution {
public:
    unordered_map<char,string>m1;
    vector<string>res;
    string curr="";
    void dfs(string digits,int index){
        if(index == digits.size())
        {
            res.push_back(curr);
        }
        string letter=m1[digits[index]];
        for(char l:letter)
        {
            curr.push_back(l);
            dfs(digits,index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        m1['2']="abc";
        m1['3']="def";
        m1['4']="ghi";
        m1['5']="jkl";
        m1['6']="mno";
        m1['7']="pqrs";
        m1['8']="tuv";
        m1['9']="wxyz";
        dfs(digits,0);
        return res;
         
    }
};
