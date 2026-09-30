class Solution {
public:
    vector<string> res;
    void dfs(int l, int r, string s, int n)
    {
        if(l == n && r == n)
        {
            res.push_back(s);
            return;
        }
        if(l > n)
        {
            return;
        }
        if(r > n)
        {
            return;
        }
        if(l < n && r <= l)
        {
            dfs(l+1, r, s + '(', n);
        }
        if(r < l)
        {
            dfs(l, r+1, s + ')', n);
        }
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(0 , 0, "", n);
        return res;
    }
};
