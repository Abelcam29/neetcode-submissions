class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int w1 = 0, w2 = 0;
        while(w1 < word1.size() && w2 < word2.size())
        {
            s.push_back(word1[w1]);
            w1++;
            s.push_back(word2[w2]);
            w2++;
        }
        if(w1 < word1.size())
        {
            s += word1.substr(w1);
        }
        if(w2 < word2.size())
        {
            s += word2.substr(w2);
        }
        return s;
    }
};