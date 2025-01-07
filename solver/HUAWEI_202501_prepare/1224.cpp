class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> times;
        int min_time = 1, max_time = 1;
        int min_num = nums[0], max_num = nums[0];
        ++times[nums[0]];

        int ans = 0;
        for (int right = 1, len = nums.size(); right < len; ++right)
        {
            int cur = nums[right];
            int cur_time = ++times[cur];
            if (cur_time > max_time)
            {
                max_time = cur_time;
                max_num = cur;
            }
            if (cur == min_num)
            {
                //维护min是O(n)的目前
                min_num = cur, min_time += 1;
                for (auto tmp : times)
                {
                    if (tmp.second < min_time)
                    {
                        min_time = tmp.second;
                        min_num = tmp.first;
                        break;
                    }
                }
            }
            if (cur_time < min_time)
            {
                min_time = cur_time;
                min_num = cur;
            }


            //删除之后所有数字还在
            if (max_time - min_time == 1)
            {
                int tmp = right + 1 - min_time * times.size();
                if (tmp == 1) {ans = right; /*cout<<"case 1: right = "<<right<<" ans = "<<ans<<'\n';*/}
            }

            if (max_time == min_time && times.size() == 1) {ans = right; /*cout<<"case 2: right = "<<right<<" ans = "<<ans<<'\n';*/}

            //删除了一个只出现一次的数字
            if (min_time == 1 && (right % (times.size() - 1) == 0))
            {
                int t = right / (times.size() - 1);
                bool flag = true;
                for (auto tmp : times)
                {
                    if (tmp.first != min_num && tmp.second != t) {flag = false; break;}
                }
                if (flag) {ans = right; /*cout<<"case 3: right = "<<right<<" ans = "<<ans<<'\n';*/}
            }

            // cout<<"----------------------\n";
            //     cout<<"right = "<<right<<" min_time = "<<min_time<<" min_num = "<<min_num<<" max_time = "<<max_time<<" max_num = "<<max_num<<'\n';
            //     for (auto tmp : times)
            //     {
            //         cout<<"("<<tmp.first<<", "<<tmp.second<<") ";
            //     }
            //     cout<<"\n----------------------\n";
        }

        return ans + 1;
    }
};