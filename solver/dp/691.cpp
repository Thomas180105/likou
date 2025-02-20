//（1）首先是dp数组的定义问题，想到状态压缩的心路过程后期复盘一下，经验不够导致不够迅速。以及dp[i][state] v.s dp[state] + 记忆化搜索的对比
//（2）然后是记忆化搜索写的少，这里一定要注意区分“该dp未求解”以及“该dp无可行方案”两者的区别，如果两者都是赋值为-1会TLE，因为是假的记忆化
//（3）最后是dp转移的时候要注意判断preState的dp是不是合法的，不合法就不要转移了
// 题解中用dp[mask] = m + 1;巧妙解决了（2）（3）两个问题，可以多多借鉴一下这个trick
class Solution {
private:
    static const int maxTLen = 15;
    int get(vector<int> &dp, const vector<vector<int>>& charCnt, const string &target, int state)
    {
        // cout<<"now get dp["<<state<<"]\n";
        if (dp[state] != -2) return dp[state];
        for (auto counter : charCnt)
        {
            int preState = state;
            for (int i = 0; i < maxTLen; ++i)
            {
                if (((state >> i) & 1) && counter[target[i] - 'a'])
                {
                    --counter[target[i] - 'a'];
                    preState -= 1 << i;
                }
            }
            if(preState != state)
            {
                int tmp = get(dp, charCnt, target, preState);
                if (tmp != -1) dp[state] = dp[state] == -2 ? tmp + 1 : min(dp[state], tmp + 1);
            }
        }
        if (dp[state] == -2) dp[state] = -1;
        return dp[state];
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        //e.g. 011 表示target[0],target[1]两个字符组成的子集需要几个sticker来完成
        vector<vector<int>> charCnt(stickers.size(), vector<int>(26));
        for (int i = 0, listSize = stickers.size(); i < listSize; ++i)
        {
            for (auto ch : stickers[i]) ++charCnt[i][ch - 'a'];
        }
        vector<int> dp(1 << target.size(), -2);//-2表示没有求解 -1 表示无可行方案
        dp[0] = 0;
        return get(dp, charCnt, target, (1 << target.size()) - 1);
    }
};