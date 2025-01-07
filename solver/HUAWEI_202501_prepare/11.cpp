// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         //从左往右扫，单调栈可以得到每一个位置左边第一个大于等于其高度的横坐标
//         //从右往左扫，单调栈可以得到每一个位置右边第一个大于等于其高度的横坐标
//         //对于每一个位置更新ans
//         int len = height.size();
//         stack<pair<int, int>> stk;//(高度,横坐标)
//         vector<int> left(len);
//         vector<int> right(len);

//         for (int i = 0; i < len; ++i)
//         {
//             while(!stk.empty() && stk.top().first <= height[i])
//             {
//                 right[stk.top().second] = i;
//                 stk.pop();
//             }
//             stk.push({height[i], i});
//         }

//         while(!stk.empty())
//         {
//             right[stk.top().second] = stk.top().second;
//             stk.pop();
//         }

//         for (int i = len - 1; i >= 0; --i)
//         {
//             while(!stk.empty() && stk.top().first <= height[i])
//             {
//                 left[stk.top().second] = i;
//                 stk.pop();
//             }
//             stk.push({height[i], i});
//         }

//         while(!stk.empty())
//         {
//             left[stk.top().second] = stk.top().second;
//             stk.pop();
//         }

//         int ans = 0;
//         for (int i = 0; i < len; ++i)
//         {
//             cout<<"i = "<<i<<" left = "<<left[i]<<" right = "<<right[i]<<" res = "<<height[i] * (right[i] - left[i])<<'\n';
//             ans = max(ans, height[i] * (right[i] - left[i]));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int ans = 0;
        while(l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return ans;
    }
};