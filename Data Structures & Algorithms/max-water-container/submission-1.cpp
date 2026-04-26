class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, res = 0;
        while(l < r)
        {
            int area = (r - l) * min(heights[l], heights[r]);
            res = max(area, res);
            if(heights[r] < heights[l])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return res;
    }
};
