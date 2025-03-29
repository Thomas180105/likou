class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt1 = 0, cnt2 = 0;//1:'X' 2:'O'
        //首先是判定数量
        //在此基础上，需要判定是不是在游戏结束之后还放置字符

        //比如下面这个就不符合
        //X O O
        //X X O
        //X X O

        //而下面这个符合
        //X O X
        //X X O
        //X O O

        //提出猜想：游戏结束之后玩家不准放置字符，则如果最终棋局中有人连线，那么另外一方不可以连线
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == 'X') ++cnt1;
                else if (board[i][j] == 'O') ++cnt2;
            }
        }

        if (cnt1 > cnt2 + 1 || cnt1 < cnt2) return false;

        //开始检查双方获胜情况
        bool win1 = false, win2 = false;
        for (int i = 0; i < 3; ++i)
        {
            bool all1 = true, all2 = true;
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == 'X') all2 = false;
                else if (board[i][j] == 'O') all1 = false;
                else all1 = all2 = false;
            }
            if (all1) win1 = true;
            else if (all2) win2 = true;
        }

        for (int j = 0; j < 3; ++j)
        {
            bool all1 = true, all2 = true;
            for (int i = 0; i < 3; ++i)
            {
                if (board[i][j] == 'X') all2 = false;
                else if (board[i][j] == 'O') all1 = false;
                else all1 = all2 = false;
            }
            if (all1) win1 = true;
            else if (all2) win2 = true;
        }

        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') win1 = true;
        else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') win1 = true;
        else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') win2 = true;
        else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') win2 = true;

        // cout<<"cnt1 = "<<cnt1<<", cnt2 = "<<cnt2<<", win1 = "<<win1<<", win2 = "<<win2<<'\n';
        if (win1 && win2) return false;
        //还是不充分，比如
        //O X X
        //X O X
        //O X O
        if (win2 && cnt1 != cnt2) return false;
        if (win1 && cnt1 != cnt2 + 1) return false;
        return true;
    }
};