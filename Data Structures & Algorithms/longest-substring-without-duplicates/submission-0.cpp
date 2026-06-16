class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int longmax = 0;
        if(s.size() <= 1)
        {
            return s.size();
        }
        unordered_set<char> mp;
        while(r < s.size())
        {
            if(mp.find(s[r]) != mp.end())
            {
                while(s[l] != s[r])
                {
                    mp.erase(s[l]);
                    l++;
                }
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[r]);
            r++;
            longmax = max(longmax, (r-l));
        }
        return longmax;
    }
};
