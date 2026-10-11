class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, int comp, vector<int>& sum, int target, int start)
    {
        if(comp == 0)
        {
            res.push_back(sum);
        }
        if(comp < 0)
        {
            return;
        }
        for(int i = start; i < nums.size(); i++)
        {
            comp = comp - nums[i];
            if(comp >= 0)
            {
                sum.push_back(nums[i]);
                dfs(nums, comp, sum, target, i);
                sum.pop_back();
                comp += nums[i];
            }
            else
            {
                comp += nums[i];
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        vector<int> sum;
        dfs(nums, target, sum, target, 0);
        return res;
    }
};
