class Solution {
public:
    bool isPalindrome(string s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
        l++;
        r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int r = s.size() - 1, l = 0;
        while(l < r)
        {
            if( s[l] != s[r])
            {
                return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);    
            }
            l++;
            r--;
        }
        return true;
    }
};