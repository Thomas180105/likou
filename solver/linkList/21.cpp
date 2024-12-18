class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1000);
        ListNode* tail = head;
        // TODO: 判断是否需要特判 DONE: 不需要
        while(list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val) {tail = tail->next = list2; list2 = list2->next;}
            else {tail = tail->next = list1; list1 = list1->next;}
        }

        tail->next = (list1 == nullptr) ? list2 : list1; //即使均为nullptr也不会出问题

        return head->next;
    }
};