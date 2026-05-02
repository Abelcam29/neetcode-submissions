class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = n + m;
        int half = total / 2;
        double res = 0;
        int left = 0, right = n - 1, mid1 = 0, mid2 = 0;
        int left1 = 0, left2 = 0, right1 = 0, right2 = 0;

        while (true)
        {
            mid1 = floor((double) (right + left) /2);
            mid2 = half - mid1 - 2;
            left1 = mid1 < 0 ? INT_MIN : nums1[mid1];
            left2 = mid2 < 0 ? INT_MIN : nums2[mid2];
            right1 = mid1 + 1 >= n ? INT_MAX : nums1[mid1 + 1];
            right2 = mid2 + 1 >= m ? INT_MAX : nums2[mid2 + 1];

            if(left1 <= right2 && left2 <= right1)
            {
                if(total % 2 == 0)
                {
                    res = ((double) max(left1,left2) + min(right1, right2)) / 2;
                }
                else
                {
                    res = min(right1, right2);
                }
                break;
            }
            if(left1 > right2)
            {
                right = mid1 - 1;

            }
            else
            {
                left = mid1 + 1;
            }
        }

        return res;
    }
};
