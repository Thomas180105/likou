class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int l = points.size();

        int ans = 0;
        for (int i = 0; i < l; ++i)
        {
            vector<int> cur = points[i];
            int same = 0, same_x = 0;
            unordered_map<double, int> slope;
            for (int j = 0; j < l; ++j)
            {
                // if (i == j) continue;
                vector<int> tmp = points[j];
                if (tmp[0] == cur[0])
                {
                    tmp[1] == cur[1] ? ++same : ++same_x;
                    continue;
                }
                ++slope[static_cast<double>((cur[1] - tmp[1])) / (cur[0] - tmp[0])];
            }

            int ans_i = same_x;
            // cout<<"i = "<<i<<" same = "<<same<<" same_x = "<<same_x<<' ';
            for (auto [s, cnt] : slope)
            {
                ans_i = max(ans_i, cnt);
                // cout<<"("<<s<<", "<<cnt<<") ";
            }
            ans_i += same;

            ans = max(ans, ans_i);
        }

        return ans;
    }
};