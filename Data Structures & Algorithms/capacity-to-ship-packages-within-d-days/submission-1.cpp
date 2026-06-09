class Solution {
public:
    bool feasible(vector<int>& weights, int days, int mid)
    {
        int day = 1;
        int j = 0; //time
        for(int w : weights)
        {
            if((j + w) > mid)
            {
                j = w;
                day++;
            }
            else
            {
                j += w;
            }
        }
        if(day <= days)
        {
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res = 0;
        bool ans = false;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            ans = feasible(weights, days, mid);
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