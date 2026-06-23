class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
        {
            return "";
        }
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        unordered_map<char, int> dict;
        string res = "", candt = "";
        int req = 0;
        for(int i = 0; i < t.size(); i++)
        {
            dict[t[i]]++;
        }
        int n = dict.size();
        while(r < s.size())
        {
            if(dict.count(s[r]))
            {
                mp[s[r]]++;
                if(mp[s[r]] == dict[s[r]])
                {
                    req++;
                }
            }
            if(req == n)
            {
                while(req == n)
                {
                    if(dict.count(s[l]))
                    {
                        mp[s[l]]--;
                        if(mp[s[l]] < dict[s[l]])
                        {
                            req--;
                        }
                    }
                    candt = s.substr(l, r - l + 1);
                    l++;
                }
                if(candt.size() < res.size() || res == "")
                {
                    res = candt;
                }
                else if(candt.size() == res.size())
                {
                    if(candt.compare(res) < 0)
                    {
                        res = candt;
                    }
                }
            }
            r++;
        }
        return res;
    }
};
