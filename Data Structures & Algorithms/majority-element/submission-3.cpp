class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int l = 0, temp = 0;
        unordered_map <int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto const& [n, m]: mp)
        {
            if(temp < m)
            {
                temp = m;
                l = n;
            }
        }
        return l;
    }
};