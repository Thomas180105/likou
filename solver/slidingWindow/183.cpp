class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        //单调双端队列板子题,从左往右，严格单减
        deque<int> dq;
        vector<int> res;
        for (int i = 0, len = heights.size(); i < len; ++i)
        {
            if (dq.front() == i - limit) dq.pop_front();
            while(!dq.empty() && heights[i] >= heights[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (i >= limit - 1) res.emplace_back(heights[dq.front()]);
        }
        return res;
    }
};