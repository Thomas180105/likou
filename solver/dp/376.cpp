class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();

        vector<int> up(len, 1);//about to get up
        vector<int> down(len, 1);//about to get down

        int ans = 1;
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j]) down[i] = max(down[i], up[j] + 1);
                else if (nums[i] < nums[j]) up[i] = max(up[i], down[j] + 1);
            }
            ans = max(ans, up[i]);
            ans = max(ans, down[i]);
        }

        return ans;
    }
};