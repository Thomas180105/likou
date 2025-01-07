//用时
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = -1, r = 0, len = nums.size(), ans = 0;
        int curOr = 0;
        while(++l < len && r < len)
        {
            if (l) curOr ^= nums[l - 1];
            while(r < len && ((curOr & nums[r]) == 0)) {curOr |= nums[r]; ++r;} //返回之后r的值是当前l不能满足的第一个值,注意是结尾时++
            ans = max(ans, r - l);
        }
        return ans;
    }
};

// class Solution {
// private:
//     void printInBinary(int num)
//     {
//         while(num) 
//         {
//             int cur = num & 1;
//             cout<<cur;
//             num >>= 1;
//         }
//     }

//     void printVecInBinary(vector<int>& nums)
//     {
//         cout<<"the vec member is:\n";
//         for (auto tmp : nums) {printInBinary(tmp); cout<<" ";}
//         cout<<'\n';
//     }
// public:
//     int longestNiceSubarray(vector<int>& nums) {
//         int l = -1, r = 0, len = nums.size(), ans = 0;

//         printVecInBinary(nums);
//         int curOr = 0;
//         while(++l < len && r < len)
//         {
//             if (l) curOr ^= nums[l - 1];

//             cout<<"l = "<<l<<" curOr = ";
//             printInBinary(curOr);
//             cout<<"\n";

//             while(r < len && ((curOr & nums[r]) == 0)) 
//             {   
//                 cout<<"add nums[r]: ";
//                 printInBinary(nums[r]);
//                 curOr |= nums[r];
//                 cout<<" now r = "<<r<<" curOr = ";
//                 printInBinary(curOr);
//                 cout<<"\n";
//                 ++r; 
//             } //返回之后r的值是当前l不能满足的第一个值
//             ans = max(ans, r - l);
//         }
//         return ans;
//     }
// };