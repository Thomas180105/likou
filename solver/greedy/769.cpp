class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int index = 0;
        int cnt = 0, curMax = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            curMax = max(curMax, arr[i]);
            if (i == curMax) ++cnt;
        }
        return cnt;
    }
};