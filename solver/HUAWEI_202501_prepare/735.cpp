//用时 14：37
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        vector<int> positive;
        for (int i = 0, len = asteroids.size(); i < len; ++i)
        {
            if (asteroids[i] > 0) positive.push_back(asteroids[i]);
            else
            {
                if (positive.empty()) res.push_back(asteroids[i]);
                else
                {
                    int test = -asteroids[i];
                    bool flag = true;
                    while(!positive.empty())
                    {
                        if (positive.back() < test) positive.pop_back();
                        else if (positive.back() == test) {positive.pop_back(); flag = false; break;}
                        else {flag = false; break;}
                    }
                    if (flag) res.push_back(asteroids[i]);
                }
            }
        }

        for (auto tmp : positive) res.push_back(tmp);
        return res;
    }
};