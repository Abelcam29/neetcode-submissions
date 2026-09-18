class Solution {
public:
    int dfs(vector<int>& nums, int i, int k)
    {
        if(i == nums.size())
        {
            return k;
        }
        int ic = dfs(nums, i + 1, k ^ nums[i]);
        int e = dfs(nums, i + 1, k);
        return ic + e;
    }
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};