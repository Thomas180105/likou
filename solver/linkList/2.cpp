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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1, nullptr);
        ListNode* cur = dummyHead;
        int carry = 0;
        while(l1 && l2)
        {
            cur = cur->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        for (; l1; l1 = l1->next)
        {
            cur = cur->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
        }
        for (; l2; l2 = l2->next)
        {
            cur = cur->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
        }
        if (carry) cur = cur->next = new ListNode(carry);//第一次写忘记了这个
        return dummyHead->next;
    }
};