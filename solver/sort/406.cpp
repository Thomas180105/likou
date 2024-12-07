class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        int peopleCnt = people.size();
        vector<vector<int>> ans;

        for (auto person : people)
        {
            int k = person[1], l = ans.size(), index = 0;
            for (; index < l && k; ++index)
            {
                if (cmp(ans[index], person)) --k;
            }
            ans.resize(l + 1);
            for (int j = l; j >= index + 1; --j) ans[j] = ans[j - 1];
            ans[index] = person;
        }

        return ans;
    }
private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
    }
};