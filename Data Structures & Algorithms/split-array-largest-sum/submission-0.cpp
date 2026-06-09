class Solution {
public:
    bool feasible(vector<int>& nums, int k, int mid)
    {
        int j = 0;
        int z = 1;
        //MID = TIMEMAX, k = coworkers, z = worker, j = time
        for(int t : nums)
        {
            if((j + t) > mid)
            {
                j = t;
                z++;
            }
            else
            {
                j += t;
            }
        }
        if(z <= k)
        {
            return true;
        }
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        bool ans = false;
        int res = 0;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            ans = feasible(nums, k, mid);
            if(ans)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};