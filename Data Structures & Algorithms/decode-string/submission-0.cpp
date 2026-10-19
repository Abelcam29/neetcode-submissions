class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> str;
        string curr = "";
        int k = 0;
        for (char c : s)
        {
            if(isdigit(c))
            {
                k = k * 10 + (c - '0');
            }
            else if(c == '[')
            {
                count.push(k);
                str.push(curr);
                curr = "";
                k = 0;
            }
            else if(c == ']')
            {
                int repeat = count.top();
                count.pop();

                string decode = str.top();
                str.pop();
                for(int i = 0; i < repeat; i++)
                {
                    decode += curr;
                }
                curr = decode;
            }
            else
            {
                curr += c;
            }
        }
        return curr;
    }
};