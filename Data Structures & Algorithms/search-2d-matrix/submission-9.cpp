class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int n = matrix[0].size() - 1;
        int r = n;
        int level = 0;
        if(matrix.size() > 1)
        {
            while(level < matrix.size() - 1 && matrix[level][l] < target && matrix[level][r] < target)
            {
                level++;
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
