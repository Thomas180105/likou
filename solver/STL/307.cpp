// class NumArray {
// private:
//     int n;
//     vector<int> segTree;

//     void build(int node, int st, int ed, vector<int> &nums)
//     {
//         if (st == ed) {segTree[node] = nums[st]; return;}
//         int mid = st + (ed - st) / 2;
//         build(node * 2 + 1, st, mid, nums);
//         build(node * 2 + 2, mid + 1, ed, nums);
//         segTree[node] = segTree[node * 2 + 1] + segTree[node * 2 + 2];
//     }

//     void changePoint(int index, int val, int node, int st, int ed)
//     {
//         //递归出口
//         if (st == ed) {segTree[node] = val; return;}

//         //向下分治
//         int mid = st + (ed - st) / 2;
//         if (index <= mid) changePoint(index, val, node * 2 + 1, st, mid);
//         else changePoint(index, val, node * 2 + 2, mid + 1, ed);

//         //回来更新信息
//         segTree[node] = segTree[node * 2 + 1] + segTree[node * 2 + 2];
//     }

//     int queryRange(int qst, int qed, int node, int st, int ed)
//     {
//         //递归出口
//         if (st >= qst && ed <= qed) return segTree[node];

//         int ans = 0, mid = st + (ed - st) / 2;
//         if (qst <= mid) ans += queryRange(qst, qed, node * 2 + 1, st, mid);
//         if (qed > mid) ans += queryRange(qst, qed, node * 2 + 2, mid + 1, ed);

//         return ans;
//     }
// public:
//     NumArray(vector<int>& nums): n(nums.size()), segTree(n * 4) {
//         build(0, 0, n - 1, nums);
//     }

//     void update(int index, int val) {
//         changePoint(index, val, 0, 0, n - 1);
//     }

//     int sumRange(int left, int right) {
//         return queryRange(left, right, 0, 0, n - 1);
//     }
// };

class NumArray {
private:
    int n;
    vector<int> tree;
    vector<int> &nums;

    int lowbit(int x) {return x & -x;}

    void add(int index, int val)
    {
        while(index <= n)
        {
            tree[index] += val;
            index += lowbit(index);
        }
    }

    int prefix(int index)
    {
        int sum = 0;
        while(index)
        {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums): n(nums.size()), tree(n + 1), nums(nums) {
        for (int i = 0; i < n; ++i) add(i + 1, nums[i]);
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return prefix(right + 1) - prefix(left);
    }
};