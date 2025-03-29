class Solution {
private:
    void dfs(vector<vector<int>> &ans, const vector<int>& nums, vector<int>& son, vector<bool> &visited, int pos, int len)
    {
        if (pos == len)
        {
            ans.push_back(son);
            return;
        }

        for (int i = pos; i < len; ++i)//下一个选i
        {
            if (i && !visited[i - 1] && nums[i - 1] == nums[i]) continue;

            son.push_back(nums[i]);
            visited[i] = true;
            dfs(ans, nums, son, visited, i + 1, len);
            visited[i] = false;
            son.pop_back();
        }
        dfs(ans, nums, son, visited, len, len);//别忘记可以不选
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        vector<int> son;
        dfs(ans, nums, son, visited, 0, n);
        return ans;
    }
};