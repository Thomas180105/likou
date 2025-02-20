// //下面是直接用排序的做法
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> hash;
//         for (auto n : nums) ++hash[n];
//         vector<pair<int, int>> vec;
//         for (auto itr = hash.begin(); itr != hash.end(); ++itr) vec.emplace_back(itr->first, itr->second);
//         sort(vec.begin(), vec.end(), [] (const pair<int, int>& a, const pair<int, int>& b){
//             return a.second > b.second;
//         });
//         vector<int> res;
//         for (int i = 0; i < k; ++i) res.push_back(vec[i].first);
//         return  res;
//     }
// };

//下面是用堆的做法,但是比较无脑，是将所有元素入堆再pop，这样是nlogn + klogn，其中建堆的时候可以优化成原地建堆，这样从nloog降低到n。
// class Solution {
// private:
//     struct cmp{
//         bool operator()(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}
//     };
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> hash;
//         for (auto n : nums) ++hash[n];
//         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;

//         for (auto itr = hash.begin(); itr != hash.end(); ++itr) que.push({itr->first, itr->second});
//         vector<int> res;
//         while(k--)
//         {
//             res.push_back(que.top().first);
//             que.pop();
//         }
//         return  res;
//     }
// };

//现在用的所有元素入堆再pop的无脑做法，不过建堆的时候聪明一点使用了原地建堆，这样总共是n + klogn
//我们回忆一下为什么原地建堆的有关知识点
//（1）算法过程：从第一个非叶节点向下过滤调整，其中叶节点高度逐渐变高
//（2）算法正确性证明：考虑对堆的规模进行归纳证明
//（3）算法时间复杂度是O(n)证明：考虑对于堆的规模进行归纳证明，也可以直接错位相减直接求算
//（4）STL中有make_heap接口，具体见下
// class Solution {
// private:
//     struct cmp{
//         bool operator()(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}
//     };
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> hash;
//         for (auto n : nums) ++hash[n];
//         vector<pair<int, int>> vec(hash.begin(), hash.end());
//         make_heap(vec.begin(), vec.end(), cmp());
//         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que(cmp(), move(vec));
//         vector<int> res;
//         while(k--)
//         {
//             res.push_back(que.top().first);
//             que.pop();
//         }
//         return  res;
//     }
// };

//下面是正常使用堆的做法，堆中元素不超过k，进行最多O(n)次push和pop，所以是nlogk
// class Solution {
// private:
//     struct cmp{
//         bool operator()(const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;} //小顶堆
//     };
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> hash;
//         for (auto n : nums) ++hash[n];
//         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
//         for (auto itr = hash.begin(); itr != hash.end(); ++itr)
//         {
//             if (que.size() < k) que.push(*itr);
//             else if (itr->second > que.top().second) {que.pop(); que.push(*itr);} //小顶堆的top此时一定不是答案，丢掉
//         }
//         vector<int> res;
//         while(k--)
//         {
//             res.push_back(que.top().first);
//             que.pop();
//         }
//         return res;
//     }
// };

//考虑到second的范围是被nums.size()bound住的，这样有一个较小的上界我们也可以考虑使用桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> times;
        int l = nums.size();
        for (int i = 0; i < l; ++i) ++times[nums[i]];//(num, time)

        vector<vector<int>> freq(nums.size() + 1);

        for (auto tmp : times) freq[tmp.second].push_back(tmp.first);

        vector<int> ans;
        for (int i = freq.size() - 1; i >= 0 && ans.size() < k; --i)
        {
            if (freq[i].empty()) continue;
            for (auto tmp : freq[i])
            {
                if (ans.size() < k) ans.push_back(tmp);
            }
        }
        return ans;
    }
};

//至此我们总结一下这个题目的思路
//最直白的排序：O(nlogn)
//所有元素入堆再pop：相当于堆排序 采用原地建堆优化后 O(n + klogn)
//使用最小堆来维护可能是答案的集合： O(nlogk)
//观察到待排序元素（即出现频率）有一个比较好的上界n，上桶排序: O(n)