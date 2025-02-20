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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *oddHead = new ListNode(-200, nullptr);
        ListNode *oddTail = oddHead;
        ListNode *evenHead = new ListNode(-200, nullptr);
        ListNode *evenTail = evenHead;
        int cnt = 1;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *tmp = cur;
            cur = cur->next;
            if (cnt++ % 2 == 1) oddTail = oddTail->next = tmp;
            else evenTail = evenTail->next = tmp;
            tmp->next = nullptr;
        }
        oddTail->next = evenHead->next;
        return oddHead->next;
    }
};