class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {{'}', '{'}, {']', '['}, {')','('}};
        stack<char> pl;
        for(char c : s)
        {
            auto it = mp.find(c);
            if(it != mp.end())
            {
                if(pl.empty() || pl.top() != it->second)
                {
                    return false;
                }
                pl.pop();
            }
            else
            {
                pl.push(c);
            }
        }
        return pl.empty();
    }
};
