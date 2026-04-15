class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.size()-1;
        while(L < R)
        {
            if(isalnum(s[L]) || isalnum(s[R]))
            {
                if(isalnum(s[L]))
                {
                    if(isalnum(s[R]))
                    {
                        if(tolower(s[L]) == tolower(s[R]))
                        {
                            R--;
                            L++;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        R--;
                    }
                }
                else
                {
                    L++;
                }
            }
            else
            {
                L++;
                R--;
            }
            
        }
        return true;
    }
};
