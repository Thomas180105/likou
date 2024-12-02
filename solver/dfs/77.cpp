#include<stack>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(cur, 1, n, k, ans);
        return ans;
    }
    void dfs(vector<int> &cur, int index, int n, int k, vector<vector<int>> &ans)//index表示剩余可用数字为index到n
    {
        if (cur.size() == k)
        {
            ans.push_back(cur);
            return;
        }

        int l = n + 1 - k + cur.size();
        for (int i = index; i <= l; ++i)
        {
            cur.push_back(i);
            dfs(cur, i + 1, n, k, ans);
            cur.pop_back();
        }
    }
};