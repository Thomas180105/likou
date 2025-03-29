class Solution {
private:
    class BIT{
    private:
        int n;//权值树状数组中最大下标是n
        vector<int> nums;
    public:
        BIT(int n): n(n), nums(n + 1, 0) {}
        int lowbit(int x) {return x & -x;}
        int sum(int index)//查询[1, index]
        {
            int ans = 0;
            while(index)
            {
                ans += nums[index];
                index -= lowbit(index);
            }
            return ans;
        }
        int query(int l, int r) //l与r在[1, n]范围内,查询[l, r]
        {
            return sum(r) - sum(l - 1);
        }
        void add(int index, int val)
        {
            while(index <= n)
            {
                nums[index] += val;
                index += lowbit(index);
            }
        }
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        //直接树状数组可以直接做，时间在nlogn
        //分治思想也可以做，就是归并排序和双指针统计贡献，注意要返回一个数组来表示当前子序列中的index对应到原来数组中的下标
        int len = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> hash;
        for (int i = 0; i < len; ++i) hash[tmp[i]] = i + 1;

        BIT hst(len);
        vector<int> ans(len);
        for (int i = len - 1; i >= 0; --i)
        {
            ans[i] = hst.sum(hash[nums[i]] - 1);
            hst.add(hash[nums[i]], 1);
        }
        return ans;
    }
};