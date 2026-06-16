class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> dict(26, 0);
        vector<int> d1(26, 0);
        for(int i = 0; i < s1.size(); i++)
        {
            dict[s1[i] - 'a']++;
        }
        for(int i = 0; i < s1.size(); i++)
        {
            d1[s2[i] - 'a']++;
        }
        if(d1 == dict)
        {
            return true;
        }
        for(int i = s1.size(); i < s2.size(); i++)
        {
            d1[s2[i - s1.size()] - 'a']--;
            d1[s2[i] - 'a']++;
            if(d1 == dict)
            {
                return true;
            }
        }
        return false;
    }
};
