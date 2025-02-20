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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *pre = dummyHead;
        ListNode *nxt = dummyHead->next;
        int cnt = 0;
        while(nxt) {++cnt; nxt = nxt->next;}
        n = cnt + 1 - n, nxt = dummyHead->next;
        while(--n)
        {
            pre = pre->next;
            nxt = nxt->next;
        }
        if (nxt) {pre->next = nxt->next; delete nxt;}
        return dummyHead->next;
    }
};