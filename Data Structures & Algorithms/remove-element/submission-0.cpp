class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lim = nums.size();
        for(int i = 0; i < lim; i++)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                lim = nums.size();
                i--;
            }
        }
        return nums.size();
    }
};