class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = 0, ans = 0, len = s.size();
        for (auto child : g)
        {
            for (; index < len && child > s[index]; ++index);
            if (index < len) {++ans; ++index;}
        }
        return ans;
    }
};