class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> tmp(m + n);
        // int index1 = 0, index2 = 0, cnt = 0;
        // while(index1 < m && index2 < n)
        // {
        //     if (nums1[index1] <= nums2[index2]) tmp[cnt++] = nums1[index1++];
        //     else tmp[cnt++] = nums2[index2++];
        // }
        // while(index1 < m) tmp[cnt++] = nums1[index1++];
        // while(index2 < n) tmp[cnt++] = nums2[index2++];
        // swap(tmp, nums1);
        int pos = m-- + n-- - 1;
        while(m >= 0 && n>= 0) nums1[pos--] = (nums1[m] >= nums2[n]) ? nums1[m--] : nums2[n--];
        while(n >= 0) nums1[pos--] = nums2[n--];
    }
};