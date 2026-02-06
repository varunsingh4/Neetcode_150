class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        stack<char>s2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] =='[' || s[i] =='{')
            {
                s1.push(s[i]);
            }
            else{

                
                if(s1.size()==0)
                {
                    return false;
                }
                char ch=s1.top();
                s1.pop();
                if(ch == '(' && s[i] ==')' || ch == '[' && s[i] ==']' || ch == '{' && s[i] =='}')
                {
                    continue;

                }
                else{
                    return false;
                }
            }
        }
        return s1.empty();
    }
           
};
