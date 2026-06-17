class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end()); //4
        int l = 1;
        int res = r;
        while(l <= r)
        {            
            long long hours = 0;
            int mid = l + (r - l) / 2; // 2
            for(int i = 0; i < piles.size(); i++)
            {
                hours += ceil(static_cast<double>(piles[i]) / mid);
            }
            if(hours <= h)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};
