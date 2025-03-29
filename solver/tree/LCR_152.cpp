class Solution {
private:
    bool dfs(const vector<int>& postorder, int st, int ed)//[st, ed]
    {
        if (st >= ed) return true;

        int pivot = postorder[ed];
        int pos1 = st;
        for (; pos1 < ed; ++pos1)
        {
            if (postorder[pos1] > pivot) break;
        }
        //[st, pos1 - 1]
        for (int pos2 = pos1; pos2 < ed; ++pos2)
        {
            if (postorder[pos2] <= pivot) return false;
        }
        return dfs(postorder, st, pos1 - 1) && dfs(postorder, pos1, ed - 1);
    }
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        //二叉搜索树的中序遍历结果是从小到大的数组
        //整体上可以考虑递归做法
        //[4, 9, 6, 5, 8]->当前根是8，然后遍历前面的
        //[4]为左子树
        //[9, 6, 5]为右子树
        //划分的时候就出现了问题，直接return false;
        //否则递归下去
        return dfs(postorder, 0, postorder.size() - 1);
    }
};