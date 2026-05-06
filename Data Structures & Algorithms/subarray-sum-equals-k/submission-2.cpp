class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sa = 0;
        int sua = 0;
        mp[0]++;
        for(int i = 0; i < nums.size(); i++)
        {
            sa += nums[i];
            int objetivo = sa - k;
            if(mp.find(objetivo) != mp.end())
            {
                sua += mp[objetivo];
            }
            mp[sa]++;
        }
        return sua;
    }
};