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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;

        while(cur->next && cur->next->next)
        {
            ListNode *first = cur->next;
            ListNode *second = first->next;
            cur->next = second;
            first->next = second->next;
            second->next = first;
            cur = first;
        }

        return dummy->next;
    }
};