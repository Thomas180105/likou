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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);

        ListNode *start = dummy;
        for (int i = 0; i < left - 1; ++i) start = start->next;

        ListNode *cur = start->next;

        for (int i = 0; i < right - left; ++i)
        {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = start->next;
            start->next = tmp;
        }

        return dummy->next;

    }
};