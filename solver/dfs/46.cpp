#include<stack>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }

    void backtracking(vector<int> &cur, int index, vector<vector<int>> &ans)
    {
        if (index == cur.size() - 1)
        {
            ans.push_back(cur);
            return;
        }

        int l = cur.size();
        for (int i = index; i < l; ++i)
        {
            swap(cur[index], cur[i]);
            backtracking(cur, index + 1, ans);
            swap(cur[i], cur[index]);
        }
    }
};

static int main_test()
{
    vector<int> nums{1, 2, 3};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for (auto &v: ans)
    {
        for (auto &x: v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}