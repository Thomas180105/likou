#include<stack>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans;
        vector<int> cur(n, 0);
        vector<bool> column(n, false);
        vector<bool> rightDiag(2 * n + 1, false);//i + j, 0 ~ 2 * n - 1
        vector<bool> leftDiag(2 * n + 1, false);//j + n - 1 - i, 0 ~ 2 * n - 1
        dfs(ans, n, 0, cur, column, rightDiag, leftDiag);
        vector<vector<string>> res;
        for (const auto &curPlacement : ans)
        {
            vector<string> curStrVec;
            for (int i = 0; i < n; ++i)
            {
                int id = curPlacement[i];
                string tmp;
                for (int i = 0; i < id; ++i) tmp += ".";
                tmp += "Q";
                for (int i = id + 1; i < n; ++i) tmp += ".";
                curStrVec.push_back(tmp);
            }
            res.push_back(curStrVec);
        }
        return res;
    }
private:
    void dfs(vector<vector<int>> &ans, int n, int index, vector<int> &cur, vector<bool> &column, vector<bool> &rightDiag, vector<bool> &leftDiag)//index之前的行都放好了，现在开始决定第index行放在哪里
    {
        if (index == n)
        {
            ans.push_back(cur);
            return;
        }

        for (int thisRow = 0; thisRow < n; ++thisRow)
        {
            if (!column[thisRow] && !rightDiag[index + thisRow] && !leftDiag[thisRow + n - 1 - index])
            {
                column[thisRow] = rightDiag[index + thisRow] = leftDiag[thisRow + n - 1 - index] = true;
                cur[index] = thisRow;
                dfs(ans, n, index + 1, cur, column, rightDiag, leftDiag);
                column[thisRow] = rightDiag[index + thisRow] = leftDiag[thisRow + n - 1 - index] = false;
            }
        }
    }
};