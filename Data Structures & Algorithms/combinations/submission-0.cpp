class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& comb, int n, int k, int start)
    {
        if(k == comb.size())
        {
            res.push_back(comb);
        }
        else
        {
            for(int i = start; i <= n; i++)
            {
                comb.push_back(i);
                dfs(comb, n, k, i+1);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> comb;
        dfs(comb, n, k, 1);
        return res;
    }
};