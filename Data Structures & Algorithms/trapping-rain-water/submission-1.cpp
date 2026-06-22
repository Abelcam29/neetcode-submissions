class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxl = height[l], maxr = height[r];
        int sum = 0;
        while(l < r)
        {
            if(height[l] < height[r])
            {
                l++;
                maxl = max(height[l], maxl);
                sum += maxl - height[l];
            }
            else
            {
                r--;
                maxr = max(height[r], maxr);
                sum += maxr - height[r];
            }
        }
        return sum;
    }
};
