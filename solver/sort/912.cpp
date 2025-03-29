class Solution {
private:
    void mergeSort(vector<int>& nums, int st, int ed)//[st, ed]
    {
        if (st == ed) return;

        int mid = st + (ed - st) / 2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid + 1, ed);
        merge(nums, st, mid, ed);
    }
    void merge(vector<int>& nums, int st, int mid, int ed)//[st, mid] [mid + 1, ed]
    {
        vector<int> tmp;
        int pos1 = st, pos2 = mid + 1;
        while(pos1 <= mid && pos2 <= ed)
        {
            if (nums[pos1] <= nums[pos2]) tmp.push_back(nums[pos1++]);
            else tmp.push_back(nums[pos2++]);
        }
        while(pos1 <= mid) tmp.push_back(nums[pos1++]);
        while(pos2 <= ed) tmp.push_back(nums[pos2++]);
        for (int i = st; i <= ed; ++i) nums[i] = tmp[i - st];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};