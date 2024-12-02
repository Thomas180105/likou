#include<stack>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, 0, i, j, m, n)) return true;
            }
        }
        return false;
    }
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
    bool dfs(vector<vector<char>>& board, const string &word, int index, int r, int c, int m, int n)
    {
        if (index == word.size()) return true;
        if (r >= 0 && r < m && c >= 0 && c < n && board[r][c] == word[index])
        {
            char tmp = 0;
            swap(tmp, board[r][c]);
            for (int i = 0; i < 4; ++i) if (dfs(board, word, index + 1, r + dr[i], c + dc[i], m, n)) return true;
            swap(tmp, board[r][c]);
        }
        return false;
    }
};