class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<bool>& visited)
    {
        if(nums.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(visited[i])
                {
                    continue;
                }
                if(i > 0 && nums[i] == nums[i-1] && !visited[i-1])
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, path, visited);
        return res;
    }
};