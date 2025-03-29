//这种题目要么树状数组，要么用分治的算法思想。这次我们写一个树状数组版本的
class Solution {
private:
    class TreeVec{
    private:
        vector<int> num;
        int sz;
        int lowbit(int x) {return x & -x;}
    public:
        TreeVec(int sz) : sz(sz), num(sz + 1) {}
        void add(int pos, int val)
        {
            while(pos <= sz)
            {
                num[pos] += val;
                pos += lowbit(pos);
            }
        }
        int sum(int pos)
        {
            int res = 0;
            while(pos)
            {
                res += num[pos];
                pos -= lowbit(pos);
            }
            return res;
        }
        int query(int l, int r) {return sum(r) - sum(l - 1);}
    };
public:
    int reversePairs(vector<int>& record) {
        set<int> tmp;
        for (auto r : record) tmp.insert(r);
        unordered_map<int, int> trans;
        int cnt = 1;
        for (auto r : tmp) trans[r] = cnt++;
        int ans = 0;
        TreeVec hst(cnt);
        for (int i = 0, rSize = record.size(); i < rSize; ++i)
        {
            ans += hst.query(trans[record[i]] + 1, cnt);
            hst.add(trans[record[i]], 1);
        }
        return ans;
    }
};