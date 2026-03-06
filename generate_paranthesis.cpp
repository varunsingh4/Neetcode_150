class Solution {
public:
    vector<string> res;

    void dfs(int n, string &curr, int open, int close) {
        if (curr.size() == 2*n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');      // choose
            dfs(n, curr, open+1, close);
            curr.pop_back();          // undo  ← BACKTRACK
        }

        if (close < open) {
            curr.push_back(')');      // choose
            dfs(n, curr, open, close+1);
            curr.pop_back();          // undo  ← BACKTRACK
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr="";
        dfs(n, curr, 0, 0);
        return res;
    }
};
