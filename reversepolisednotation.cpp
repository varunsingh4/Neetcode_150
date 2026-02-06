class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s1;

        for(int i = 0; i < tokens.size(); i++)
        {
            // FIRST check operator (avoid stoi crash)
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                string ch = tokens[i];

                string operand = s1.top();
                s1.pop();

                string operand2 = s1.top();
                s1.pop();   // <-- you missed this pop

                int a = stoi(operand2);
                int b = stoi(operand);

                if(ch == "+")
                {
                    s1.push(to_string(a + b));
                }
                else if(ch == "-")
                {
                    s1.push(to_string(a - b));
                }
                else if(ch == "*")
                {
                    s1.push(to_string(a * b));
                }
                else if(ch == "/")
                {
                    s1.push(to_string(a / b));
                }
            }
            else
            {
                // token is number
                s1.push(tokens[i]);
            }
        }

        return stoi(s1.top());
    }
};
