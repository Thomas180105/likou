//用时10:18
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        //先写M方暴力
        vector<int> res;
        for (int s_start = 0, s_len = s.size(); s_start < s_len; ++s_start)
        {
            int cur_x = startPos[0], cur_y = startPos[1];

            int cnt = 0;
            for (int i = s_start; i < s_len; ++i)
            {
                if (s[i] == 'L') --cur_y;
                else if (s[i] == 'R') ++cur_y;
                else if (s[i] == 'U') --cur_x;
                else if (s[i] == 'D') ++cur_x;
                if (cur_x >= 0 && cur_x < n && cur_y >= 0 && cur_y < n) ++cnt;
                else break;
            }
            res.push_back(cnt);
        }

        return res;
    }
};