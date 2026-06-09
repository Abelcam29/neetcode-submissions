/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, res = 0;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            res = guess(mid);
            if(res == 0)
            {
                return mid;
            }
            else if( res == 1)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};