class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> newArr = nums;
        for(int i : nums)
        {
            newArr.push_back(i);
        }
        return newArr;
    }
};