class Solution {
private:
    int len1, len2;
    unordered_set<int> hash;
    struct cmp{
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[0] > b[0];
        }
    };
    bool isValid(int idx1, int idx2)
    {
        if (idx1 >= len1 || idx2 >= len2 || hash.count(idx1 * len2 + idx2)) return false;
        hash.insert(idx1 * len2 + idx2);
        return true;
    }
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        len1 = nums1.size(), len2 = nums2.size();
        hash.clear();
        priority_queue<vector<int>, vector<vector<int>>, cmp> que;
        vector<vector<int>> ans;

        que.push({nums1[0] + nums2[0], 0, 0});
        while(k--)
        {
            auto cur = que.top();
            que.pop();
            int idx1 = cur[1], idx2 = cur[2];
            ans.push_back({nums1[idx1], nums2[idx2]});

            if (isValid(idx1 + 1, idx2)) que.push({nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2});
            if (isValid(idx1, idx2 + 1)) que.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1});
        }
        return ans;
    }
};