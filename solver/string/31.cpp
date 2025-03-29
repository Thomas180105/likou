// class Solution {
// private:
//     bool dfs(vector<int>& pre, deque<int> &next)
//     {
//         //递归出口
//         if (next.size() <= 1) return false;

//         //递归体，现在开始求解next的下一个，如果找到了直接构成答案并且返回
//         //优先尝试深度增加
//         pre.push_back(next.front());
//         next.pop_front();
//         if (dfs(pre, next)) return true;
//         next.push_front(pre.back());
//         pre.pop_back();

//         //现在开始尝试重排序
//         int pivot = next.front();
//         sort(next.begin(), next.end());
//         return next.back() > pivot;
//     }
// public:
//     void nextPermutation(vector<int>& nums) {
//         //全部先求出来再排序不可行。2^100量级
//         //记得似乎有一个专门的算法来做这件事情，但忘记具体是怎么做的了，那我们就考虑自己搓一个搜索出来

//         //先快速手玩一下
//         //求解[1, 2, 3]的下一个
//         //[1] + 求解[2, 3]的下一个
//         //递归[1 2] + 求解[3]的下一个
//         //回溯[1] + 求解[2, 3]的下一个且不能保留2
//         //return [1] + [3 2](注：将[2 3]元素全部排序。第一个元素为比原来2更大的数，剩余数字从小到大排序)

//         //求解[3 2 1]的下一个
//         //[3] + [2 1]的下一个
//         //[3 2] + [1]的下一个
//         //回溯 [3] + [2 1]的下一个且不能保留2
//         //回溯 [3 2 1]的下一个且不能保留3
//         //失败
//         //主程序返回[1 2 3]

//         vector<int> pre;
//         deque<int> dq;
//         for (auto tmp : nums) dq.push_back(tmp);
//         if (dfs(pre, dq))
//         {
//             int pos = pre.size();
//             for (int i = 0; i < pos; ++i) nums[i] = pre[i];

//             bool flag = false;
//             int pivot = dq.front();
//             for (int i = 0, len = dq.size(); i < len; ++i)
//             {
//                 if (!flag && dq[i] > pivot) {flag = true; nums[pos] = dq[i];}
//                 else nums[i + 1 + pos] = dq[i];
//             }
//         }
//         else sort(nums.begin(), nums.end());
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i >= 0)
        {
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
