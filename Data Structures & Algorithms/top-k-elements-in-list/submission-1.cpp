class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> count(nums.size()+1);
        unordered_map <int, int> freq;
        for(int i : nums)
        {
            freq[i]++;
        }
        for(auto const& [n, c] : freq)
        {
            count[c].push_back(n);
        }
        vector<int> res;
        for(int i = count.size() - 1; i >= 0; i--)
        {
            for(int n : count[i])
            {
                res.push_back(n);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }
    }
};
