class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        //看起来是先排序然后dp，这里dp[i][val]表示用前i个是否可以搞到手val，但是这样时间明显超了，换set试一试？
        int len = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());

        // set<int> sum;
        // sum.insert(0);
        // for (int i = 0; i < len; ++i)
        // {
        //     int curVal = rewardValues[i];
        //     vector<int> vec;
        //     for (auto tmp : sum)
        //     {
        //         if (tmp >= curVal) break;
        //         vec.push_back(tmp);
        //     }
        //     for (auto tmp : vec) sum.insert(tmp + curVal);
        // }
        // return *(sum.rbegin());
        //看了题解，原来是位图解决，学到了,可以快一点，注意这里j设置成全局变量，不用每次都做重复工作
        bitset<100000> f0, f1;
        f0[0] = 1;
        for (int i = 0, j = 0; i < len; ++i)
        {
            // for (int j = 0; j < rewardValues[i]; ++j) f1[j] = f0[j]; //重复工作拉满了
            while(j < rewardValues[i]) {f1[j] = f0[j]; ++j;}
            f0 |= f1 << rewardValues[i];
        }
        int res = 0;
        for (int i = f0.size(); i >= 0; --i) if (f0[i]) {res = i; break;}
        return res;
    }
};//
// Created by Lenovo on 2025/3/29.
//
