class Solution {
public:
    int mySqrt(int x) {
        long long mid = 0, res = 0;
        int l = 0, r = x;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            res = mid * mid;
            if(res == x)
            {
                return mid;
            }
            if(res < x)
            {
                l = mid + 1;
            }
            else if(res > x)
            {
                r = mid - 1;
            }
        }
        return r;
    }
};