class Solution {
public:
    string predictPartyVictory(string senate) {
        //直接贪心即可，禁止距离自己最近的敌对阵营成员即可
        // int rCnt = 0, dCnt = 0;
        // char cur;
        // for (auto s : senate)
        // {
        //     if (!rCnt && !dCnt) cur = s;
        //     if (s == 'R') dCnt ? --dCnt : ++rCnt;
        //     if (s == 'D') rCnt ? --rCnt : ++dCnt;
        // }
        // return cur == 'R' ? "Radiant" : "Dire";

        //上面的程序对于"DDRRR"输出"Radiant"，期望输出"Dire"
        // int rAlive = 0, dAlive = 0;
        // int rBanned = 0, dBanned = 0;
        // for (auto s : senate)
        // {
        //     if (s == 'R') 
        //     {
        //         if (rBanned) --rBanned;
        //         else 
        //         {
        //             dAlive ? --dAlive: ++dBanned; 
        //             ++rAlive;
        //         }
        //     }
        //     else if (s == 'D')
        //     {
        //         if (dBanned) --dBanned;
        //         else 
        //         {
        //             rAlive ? --rAlive :++rBanned; 
        //             ++dAlive;
        //         }
        //     }
        //     cout<<"rAlive = "<<rAlive<<", dAlive = "<<dAlive<<", rBanned = "<<rBanned<<", dBanned = "<<dBanned<<'\n';
        // }
        // return rAlive ? "Radiant" : "Dire";

        //还是不对，发现"DDRRR"实际上要进行两轮，那估计不能这样做了，换队列来循环模拟
        int n = senate.size();
        queue<int> queR, queD;
        for (int i = 0; i < n; ++i) senate[i] == 'R' ? queR.push(i) : queD.push(i);
        while(!queR.empty() && !queD.empty())
        {
            queR.front() < queD.front() ? queR.push(queR.front() + n) : queD.push(queD.front() + n);
            queR.pop();
            queD.pop();
        }
        return queR.empty() ? "Dire" : "Radiant";
    }
};