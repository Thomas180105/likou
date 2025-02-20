//由于数据范围很小，直接dfs即可
class Solution {
private:
    void dfs(vector<vector<int>> &res, vector<int>& candidates, vector<int> &cur, int pos, int target)
    {
        if (!target) {res.push_back(cur); return;}
        if (pos == candidates.size()) return;

        for (int i = pos, len = candidates.size(); i < len; ++i)
        {
            if (target < candidates[i]) break;
            cur.push_back(candidates[i]);
            dfs(res, candidates, cur, i, target - candidates[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, candidates, cur, 0, target);
        return res;
    }
};