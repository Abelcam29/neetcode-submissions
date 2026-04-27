class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        for(int col = 0; col < strs[0].size(); col++)
        {
            for(int row = 1; row < strs.size(); row++)
            {
                if(strs[row].size() <= col || strs[row][col] != strs[0][col])
                {
                    return strs[0].substr(0, col);
                }
            }
        }
        return strs[0];
    }
};