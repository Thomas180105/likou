class Solution {
private:
    static constexpr double epislon = 1e-6;
    static constexpr double target = 24;
    bool dfs(const vector<double> &nums)
    {
        int len = nums.size();
        if (len == 1)
        {
            if (abs(nums[0] - target) < epislon) return true;
            return false;
        }

        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                //考虑加法和乘法
                vector<double> tmp;
                for (int k = 0; k < len; ++k) if (k != i && k != j) tmp.push_back(nums[k]);
                tmp.push_back(nums[i] + nums[j]);
                if (dfs(tmp)) return true;
                tmp.pop_back();
                tmp.push_back(nums[i] * nums[j]);
                if (dfs(tmp)) return true;
            }
        }

        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (i == j) continue;
                vector<double> tmp;
                for (int k = 0; k < len; ++k) if (k != i && k != j) tmp.push_back(nums[k]);
                tmp.push_back(nums[i] - nums[j]);
                if (dfs(tmp)) return true;
                tmp.pop_back();
                tmp.push_back(nums[j] - nums[i]);
                if (dfs(tmp)) return true;
                if (abs(nums[j]) > epislon)//除法需要避免除零
                {
                    tmp.pop_back();
                    tmp.push_back(nums[i] / nums[j]);
                    if (dfs(tmp)) return true;
                }
                if (abs(nums[i]) > epislon)
                {
                    tmp.pop_back();
                    tmp.push_back(nums[j] / nums[i]);
                    if (dfs(tmp)) return true;
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> hst;
        for (auto tmp : cards) hst.push_back(tmp);
        return dfs(hst);
    }
};