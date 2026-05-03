class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = m-1, l1 = n-1, p = m + n - 1;
        if(r1 < 0)
        {
            while(l1 >= 0)
            {
                nums1[p] = nums2[l1];
                l1--;
                p--;                
            }
        }
        if(l1 < 0)
        {
            while(r1 >= 0)
            {
                nums1[p] = nums1[r1];
                r1--;
                p--;
            }
        }
        while(r1 >= 0 && l1 >= 0)
        {
            if(nums1[r1] < nums2[l1])
            {
                nums1[p] = nums2[l1];
                l1--;
            }
            else
            {
                nums1[p] = nums1[r1];
                r1--;
            }
            p--;
        }
        while(r1 >= 0)
        {
            nums1[p] = nums1[r1];
            r1--;
            p--;
        }
        while(l1 >= 0)
        {
            nums1[p] = nums2[l1];
            l1--;
            p--;
        }
    }
};