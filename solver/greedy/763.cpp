class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> charPeriod(26, vector<int>(2, -1));
        int m = s.size();

        for (int i = 0; i < m; ++i)
        {
            int cur = s[i] - 'a';
            charPeriod[cur][1] = i;
            if (charPeriod[cur][0] == -1) charPeriod[cur][0] = i;
        }

        sort(charPeriod.begin(), charPeriod.end(), cmp);

        int index = 0;
        for (; charPeriod[index][0] == -1; ++index);//while(charPeriod[index++][0] == -1)

        vector<int> ans;
        int seqBegin = charPeriod[index][0], seqEnd = charPeriod[index++][1];
        for (; index < 26; ++index)
        {
            if (charPeriod[index][0] > seqEnd)
            {
                ans.push_back(seqEnd - seqBegin + 1);
                seqBegin = charPeriod[index][0];
                seqEnd = charPeriod[index][1];
            }
            else seqEnd = max (seqEnd, charPeriod[index][1]);
        }
        ans.push_back(seqEnd - seqBegin + 1);
        return ans;
    }
    static bool cmp (const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
};