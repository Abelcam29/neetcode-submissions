class Solution {
private: 
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, int start, vector<int>& path)
    {
        res.push_back(path);
        for(int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }
};
