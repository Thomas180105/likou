class Solution {
public:
    int trap(vector<int>& height) {
        //对于每一个位置，找到其左边所有柱子的最大高度，找到其右边所有柱子的最大高度，两者取最小值即使水面在此位置的高度
        int leftMax = 0, rightMax = 0, len = height.size(), ans = 0;
        vector<int> left(len), right(len);
        for (int i = 0; i < len; ++i) {left[i] = leftMax; leftMax = max(leftMax, height[i]);}
        for (int i = len - 1; i >= 0; --i) {right[i] = rightMax; rightMax = max(rightMax, height[i]);}
        for (int i = 0; i <len; ++i) ans += ((min(right[i], left[i]) > height[i]) ? min(right[i], left[i]) - height[i] : 0);
        return ans;
    }
};