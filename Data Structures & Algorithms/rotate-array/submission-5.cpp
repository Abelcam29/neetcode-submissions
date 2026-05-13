class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
        {
            return;
        }
        k %= nums.size();
        int r = nums.size() - 1;
        int l = 0;
        while(l < r)
        {
            swap(nums[r], nums[l]);
            l++;
            r--;
        }
        l = 0;
        r = k-1;
        while(l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        r = nums.size() - 1;
        l = (k % nums.size());
        while(r > l)
        {
            swap(nums[r], nums[l]);
            r--;
            l++;
        }
    }
};