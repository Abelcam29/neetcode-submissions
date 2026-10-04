class Solution {
public:
int feasible(int mid, vector<int>& nums)
{
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] <= mid)
        {
            count++;
        }
    }
    return count;
}
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = -1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            int count = 0;
            count = feasible(mid, nums);
            if(mid < count)
            {
                r = mid - 1;
                res = mid;
            }   
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};
