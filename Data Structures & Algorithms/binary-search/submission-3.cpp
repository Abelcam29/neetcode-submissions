class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return -1;
        }
        int r = nums.size(), l = 0;
        while(l <= r)
        {
            int mid =l + (r-l)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] < target)
            {
                l = mid+1;
            }
            else if(nums[mid] > target)
            {
                r = mid-1;
            }
            else
            {
                return -1;
            }
        }
        return -1;
    }
};
