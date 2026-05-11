class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int l = 0, temp = 0;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto const& [n, m]: mp)
        {
            if(m > (nums.size() / 3))
            {
                ans.push_back(n);
            }
        }
        return ans;
    }
};