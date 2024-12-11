class Solution {
public:
    int maxProduct(vector<string>& words) {
        int l = words.size();
        vector<int> bitInfo(l, 0);
        vector<int> lenInfo(l);

        for (int i = 0; i < l; ++i)
        {
            lenInfo[i] = words[i].size();
            for (auto ch : words[i]) bitInfo[i] |= 1<<(ch - 'a');
        }

        int ans = 0;
        for (int i = 0; i < l; ++i)
        {
            for (int j = i + 1; j < l; ++j)
            {
                if((bitInfo[i] & bitInfo[j]) == 0) ans  = max(ans, lenInfo[i] * lenInfo[j]);
            }
        }
        return ans;
    }
};