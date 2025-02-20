class Solution {
private:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        vector<pair<int, int>> worker1;
        vector<pair<int, int>> worker2;
        worker1.reserve(len), worker2.reserve(len);
        for (int i = 0; i < len; ++i)
        {
            worker1.push_back({i, nums1[i]});
            worker2.push_back({i, nums2[i]});
        }
        sort(worker1.begin(), worker1.end(), cmp);
        sort(worker2.begin(), worker2.end(), cmp);

        // for (auto t : worker1) cout<<t.second<<":"<<t.first<<" ";cout<<'\n';
        // for (auto t : worker2) cout<<t.second<<":"<<t.first<<" ";cout<<'\n';

        int pos1 = 0, pos2 = 0;
        vector<int> left;
        vector<int> info(len, -1);//info[x]表示对于原来nums2，其下标x处应该放nums1[info[x]]
        while(pos1 < len && pos2 < len)
        {
            while(pos1 < len && worker1[pos1].second <= worker2[pos2].second) left.push_back(worker1[pos1++].first);
            if (pos1 < len) info[worker2[pos2].first] = worker1[pos1].first;
            ++pos1, ++pos2;
        }

        // for (int i = 0; i < len; ++i) cout<<i<<"->"<<info[i]<<" ";cout<<'\n';
        // for (auto t : left) cout<<t<<" ";cout<<'\n';

        pos1 = 0, pos2 = 0;
        int left_cnt = left.size();
        while(pos1 < left_cnt)
        {
            while(info[pos2] != -1) ++pos2;
            info[pos2] = left[pos1++];
        }

        // for (int i = 0; i < len; ++i) cout<<i<<"->"<<info[i]<<" ";cout<<'\n';

        vector<int> ans;
        for (int i = 0; i < len; ++i) ans.push_back(nums1[info[i]]);
        return ans;
    }
};