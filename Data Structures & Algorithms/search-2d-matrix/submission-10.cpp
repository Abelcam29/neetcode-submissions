class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int f = matrix[0].size() - 1;
        int c = matrix.size() - 1;
        int l = 0;
        int r = f;
        int level = 0;
        int top = 0;
        int bot = c;
        while(top <= bot)
        {
            level = bot + (top - bot) / 2;
            if(target > matrix[level].back())
            {
                top = level + 1;
            }
            else if(target < matrix[level][0])
            {
                bot = level - 1;
            }
            else
            {
                break;
            }
        }
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(matrix[level][mid] == target)
            {
                return true;
            }
            else if(matrix[level][mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};