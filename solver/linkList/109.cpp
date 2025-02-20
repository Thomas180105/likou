/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* dfs(const vector<int> &nums, int l, int r)
    {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        return new TreeNode(
                nums[mid],
                dfs(nums, l, mid - 1),
                dfs(nums, mid + 1, r)
        );
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //最朴素的想法是逐个插入在，这样实现一下AVL树的插入即可，LL、LR、RL、RR四种调整方式
        //但是考虑到现在是有序，可以考虑用别的方式
        //可以使用快慢指针来解决，不过由于要多次涉及到求链表中点，所以考虑直接使用预处理（将数据存在顺序数据结构中）
        if (!head) return nullptr;
        vector<int> nums;
        for (ListNode* cur = head; cur; cur = cur->next) nums.push_back(cur->val);
        return dfs(nums, 0, nums.size() - 1);
    }
};