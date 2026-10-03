class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        stringstream ss(path);
        string token = "";

        while(getline(ss, token, '/'))
        {
            if(token == "" || token == ".")
            {
                continue;
            }
            if(token == "..")
            {
                if(!res.empty())
                {
                    res.pop_back();
                }
            }
            else
            {
                res.push_back(token);
            }
        }
        string st = "";
        for(const string& dir : res)
        {
            st += "/" + dir;
        }
        if(st.empty())
        {
            return "/";
        }
        return st;
    }
};