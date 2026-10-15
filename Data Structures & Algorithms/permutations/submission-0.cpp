class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<bool>& visited)
    {
        if(nums.size() == path.size())
        {
            res.push_back(path);
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(visited[i])
                {
                    continue;
                }
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        dfs(nums, path, visited);
        return res;
    }
};
