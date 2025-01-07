//用时 2：15
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        vector<int> res;
        for (auto tmp : nums) ++count[tmp];
        nums.clear();
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < count[i]; ++j) nums.push_back(i);
        }
    }
};