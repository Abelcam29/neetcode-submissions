class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> mp;
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            int target = (nums[i] * -1);
            while(l < r)
            {
                if(target == (nums[l] + nums[r]))
                {
                    mp.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(nums[l] == nums[l-1] && l < r)
                    {
                        l++;
                    }
                    while(nums[r] == nums[r+1] && l < r)
                    {
                        r--;
                    }
                }
                else if((nums[l] + nums[r]) > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return mp;
    }
};
