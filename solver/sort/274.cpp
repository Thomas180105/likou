class Solution {
public:
    int hIndex(vector<int>& citations) {
        //第一眼是对于答案二分，这样是nlogC
        //也可以考虑排序，然后线性扫描，这样是nlogn，感觉这个更好，不依赖于引用数值域
        sort(citations.begin(), citations.end(), greater<int>());
        int score = 0;
        for (int i = 0, n = citations.size(); i < n; ++i)
        {
            if (citations[i] >= i + 1) score = i + 1;
        }
        return score;
    }
};