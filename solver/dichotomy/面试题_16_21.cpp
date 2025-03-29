class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        long long sum1 = 0, sum2 = 0;
        for (auto num1 : array1) sum1 += num1;
        for (auto num2 : array2) sum2 += num2;
        //如果一开始就相等如何处理？
        if ((sum1 - sum2) % 2) return {};
        int diff = (sum1 - sum2) / 2;

        sort(array2.begin(), array2.end());
        for (int i = 0, len1 = array1.size(); i < len1; ++i)
        {
            int target = array1[i] - diff, l = 0, r = array2.size() - 1;
            while(l <= r)
            {
                int mid = l + (r - l) / 2;
                if (array2[mid] == target) return {array1[i], target};
                else if (array2[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return {};
    }
};