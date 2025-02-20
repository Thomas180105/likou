class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.push_back(1);
        int pre = 1;
        for (int i = 1; i < n; ++i)
        {
            if (pre * 10 <= n) {ans.push_back(pre * 10); pre = pre * 10;}
            else
            {
                while(pre % 10 == 9 || pre + 1 > n) pre /= 10;
                ans.push_back(++pre);
            }
        }
        return ans;
    }
};