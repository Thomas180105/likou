class Solution {
private:
    bool isEnough(const vector<int>& piles, int h, int v)
    {
        int time = 0;
        for (auto tmp : piles) time += ((tmp + v - 1) / v);//向上取整
        // cout<<"now the v = "<<v<<", and totalTime = "<<time<<'\n';
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //一眼就是对答案进行二分，因为触发关键词"能......的最小速度"
        int l = 1, r = -1, len = piles.size();
        for (auto tmp : piles) r = max(r, tmp);
        while(l < r)//找出第一个足够吃完的速度
        {
            int mid = l + (r - l) / 2;//向下取整
            if (isEnough(piles, h, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};