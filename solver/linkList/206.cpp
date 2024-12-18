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
class Solution {
private:
    ListNode* res;
    //反转cur节点及之后的节点，并返回尾节点； 在临界条件进行res更新
    ListNode* dfs(ListNode* cur)
    {
        if (cur->next == nullptr)
        {
            res = cur;
            return cur;
        }

        ListNode* tail = dfs(cur->next);
        tail->next = cur;
        cur->next = nullptr; //注意此处维护，否则会成环
        return cur;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        dfs(head);
        return res;
    }
};