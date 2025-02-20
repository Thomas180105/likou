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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode *cur = head;
        while(cur->next)
        {
            if (cur->val == cur->next->val)
            {
                ListNode *to_del_node =  cur->next;
                cur->next = cur->next->next;
                delete to_del_node;
            }
            else cur = cur->next;
        }

        return head;
    }
};