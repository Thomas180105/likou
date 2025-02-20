class Solution {
private:
    void dfs(vector<int>& nums, vector<bool> &vis, vector<vector<int>> &res, vector<int> &cur, int pos)
    {
        if (pos == nums.size())
        {
            res.push_back(cur);
            return;
        }

        for (int len = nums.size(), i = 0; i < len; ++i)
        {
            if (vis[i] || (i && nums[i] == nums[i - 1] && !vis[i - 1])) continue;
            cur.push_back(nums[i]);
            vis[i] = true;
            dfs(nums, vis, res, cur, pos + 1);
            vis[i] = false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> vis(nums.size(), false);
        dfs(nums, vis, res, cur, 0);
        return res;
    }
};