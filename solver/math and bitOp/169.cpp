class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int res;
        // while(true)
        // {
        //     res = nums[rand() % nums.size()];
        //     int cnt = 0;
        //     for (auto t : nums) cnt += (t == res); 
        //     if (cnt > nums.size() / 2) break;
        // }
        // return res;
        int count = 0;
        int king = -1;
        for (auto cur : nums)
        {
            if (count == 0) {count = 1; king = cur;}
            else if (king == cur) ++count;
            else --count;
        }
        return king;
    }
};