class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        //双指针，其中left是最左侧考要不要加入的元素
        while (k--)
        {
            if (left < 0) right++;
            else if (right >= arr.size()) left--;
            else if (x - arr[left] <= arr[right] - x) left--;
            else right++;
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};