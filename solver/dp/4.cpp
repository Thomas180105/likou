class Solution {
private:
    double findKSmallNumber(const vector<int>& nums1, const vector<int>& nums2, int k, int pos1, int pos2)
    {
        //开头是特殊判断
        int len1 = nums1.size(), len2 = nums2.size();
        if (pos1 == len1) return nums2[pos2 + k - 1];
        if (pos2 == len2) return nums1[pos1 + k - 1];
        if (k == 1) return min(nums1[pos1], nums2[pos2]);

        //这里需要注意pos1 + bias1或者pos2 + bias2超过范围的情况
        int newPos1 = min(len1 - 1, pos1 + k / 2 - 1);
        int newPos2 = min(len2 - 1, pos2 + k / 2 - 1);
        if (nums1[newPos1] <= nums2[newPos2]) return findKSmallNumber(nums1, nums2, k - (newPos1 - pos1 + 1), newPos1 + 1, pos2);
        else return findKSmallNumber(nums1, nums2, k - (newPos2 - pos2 + 1), pos1, newPos2 + 1);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot % 2 == 1) return findKSmallNumber(nums1, nums2, (tot + 1) / 2, 0, 0);
        else return (findKSmallNumber(nums1, nums2, tot / 2, 0, 0) + findKSmallNumber(nums1, nums2, tot / 2 + 1, 0, 0)) / 2;
    }
};