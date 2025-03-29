class Solution {
private:
    static constexpr int mod = 1e9 + 7;
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        //看起来像是一个dp题目
        //不过显然是需要区奇偶性的
        //转移方程？转移拓扑序？
        //由于nextVisit不会向上跳跃，所以向上跳跃只能考虑挪动，所以第一次访问是比较好确定的
        //odd[i] = even[i - 1] + 1
        //第二次访问，在第一次访问基础上，需要第二次到i - 1层，但是有一个时间节省由odd[nextVisit[i]贡献
        int n = nextVisit.size();
        vector<long long> odd(n, -1);  //第一次访问房间 i 的天数
        vector<long long> even(n, -1);

        even[0] = 1;
        odd[0] = 0;

        for (int i = 1; i < n; ++i)
        {
            odd[i] = (even[i - 1] + 1) % mod;
            even[i] = (2 + odd[i] + (mod + even[i - 1] - odd[nextVisit[i]])) % mod;
        }

        return odd[n - 1];
    }
};
