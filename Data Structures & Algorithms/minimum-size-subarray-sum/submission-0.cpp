class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int maxsum = 0, longmax = INT_MAX;
        for(r; r < nums.size(); r++)
        {
            maxsum += nums[r];
            while(maxsum >= target)
            {
                longmax = min(longmax, (r - l + 1));
                maxsum -= nums[l++];
            }
        }
        if(longmax == INT_MAX)
        {
            return 0;
        }
        return longmax;
    }
};