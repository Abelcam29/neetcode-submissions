class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, vector<int>& path, int index)
    {
        res.push_back(path);
        if(path.size() <= nums.size())
        {
            for(int i = index; i < nums.size(); i++)
            {
                if(i > index && nums[i] == nums[i-1])
                {
                    continue;
                }
                path.push_back(nums[i]);
                dfs(nums, path, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
};
