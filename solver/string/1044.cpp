class Solution {
public:
    string longestDupSubstring(string s) {
        int len = s.size();
        int l = 1, r = len;
        string res;
        long long base1 = 911382629, base2 = 897987841;
        long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
        while(l < r)//找第一个不符合要求的长度
        {
            int mid = l + (r - l) / 2;

            //直接这样写hash会MLE，只能考虑字符串哈希
            // unordered_set<string> hash;
            // bool flag = false;
            // for (int i = 0; i <= len - mid; ++i) 
            // {
            //     string cur = s.substr(i, mid);
            //     if (hash.count(cur)) {flag = true; res = cur; break;}
            //     hash.insert(cur);
            // }

            //单字符串哈希被卡了？？？那就上双哈希
            bool flag = false;
            unordered_set<long long> hash1;
            unordered_set<long long> hash2;
            long long basePow1 = 1, basePow2 = 1;
            long long curVal1 = 0, curVal2 = 0;
            for (int i = 1; i < mid; ++i)
            {
                basePow1 = basePow1 * base1 % mod1;
                basePow2 = basePow2 * base2 % mod2;
            }
            for (int i = 0; i < mid; ++i)
            {
                curVal1 = (curVal1 * base1 + (s[i] - 'a' + 1)) % mod1;
                curVal2 = (curVal2 * base2 + (s[i] - 'a' + 1)) % mod2;
            }
            hash1.insert(curVal1);
            hash2.insert(curVal2);
            for (int i = 1; i <= len - mid; ++i)
            {
                curVal1 = ((curVal1 + mod1 - (basePow1 * (s[i - 1] - 'a' + 1)) % mod1) * base1 + (s[i + mid - 1] - 'a' + 1)) % mod1;
                curVal2 = ((curVal2 + mod2 - (basePow2 * (s[i - 1] - 'a' + 1)) % mod2) * base2 + (s[i + mid - 1] - 'a' + 1)) % mod2;
                if (hash1.count(curVal1) && hash2.count(curVal2)) {flag = true; res = s.substr(i, mid); break;}
                hash1.insert(curVal1);
                hash2.insert(curVal2);
            }

            if (flag) l = mid + 1;
            else r = mid;
        }
        return res;
    }
};