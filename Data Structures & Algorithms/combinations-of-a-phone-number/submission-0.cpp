class Solution {
public:
    unordered_map<char, string> mp{
        {'2', "abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5', "jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void dfs(vector<char>& path, vector<string>& res, int index, string& digits)
    {
        if(path.size() == digits.size())
        {
            string s(path.begin(), path.end());
            res.emplace_back(s);
            return;
        }
        for(char& c : mp.at(digits[index]))
        {
            path.emplace_back(c);
            dfs(path, res, index + 1, digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return {};
        }
        vector<char> path;
        vector<string> res;
        dfs(path, res, 0, digits);
        return res;
    }
};
