class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, ans = -1, last = nums.back();
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > last)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                ans = nums[mid];
            }
        }
        return ans;
    }
};
