class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp.insert(nums[i]);
        }
        int consecutivem = 0, cons = 0;
        for(int i : mp)
        {
            cons = 1;
            int x = i+1;
            while(mp.find(x) != mp.end())
            {
                cons++;
                x++;
            }
            if(cons > consecutivem)
            {
                consecutivem = cons;
                cons = 0;
            }
        }
        return consecutivem;
    }
};
