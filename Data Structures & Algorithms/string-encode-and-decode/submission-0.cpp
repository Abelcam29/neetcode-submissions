#include <cstring>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string str : strs)
        {
            int s = str.size();
            encoded.append(reinterpret_cast<const char*>(&s), sizeof(int));
            encoded.append(str);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int curr = 0;
        int total = s.size();
        while(curr < total)
        {
            int strl = 0;
            memcpy(&strl, s.data() + curr, sizeof(int));
            curr += sizeof(int);

            res.push_back(s.substr(curr, strl));
            curr += strl;
        }
        return res;
    }
};
