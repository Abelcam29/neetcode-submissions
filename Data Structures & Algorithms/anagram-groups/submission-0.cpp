class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> resmap;
        vector<vector<string>> res;
        for (string str: strs)
        {
            vector<int> abc(26, 0);
            for (char c: str)
            {
                abc[c - 'a'] += 1;
            }
            resmap[abc].push_back(str);
        }
        for(auto const& [ llave, grupo] : resmap)
        {
            res.push_back(grupo);
        }
        return res;
    }
};
