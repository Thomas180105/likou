// 1WA1AC 8:17
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *dummyNode = new ListNode(-1, head);
        if (!head) return nullptr;

        int len = 0;
        ListNode *cur = head;
        ListNode *tail;
        while(cur)
        {
            if (!cur->next) tail = cur;
            cur = cur->next;
            ++len;
        }

        k %= len;
        if (!k) return dummyNode->next;

        cur = head;
        ListNode *prev = dummyNode;
        for (int cnt = 0; cnt < len - k; ++cnt) {cur = cur->next; prev = prev->next;}

        prev->next = nullptr;
        tail->next = dummyNode->next;
        dummyNode->next = cur;
        return dummyNode->next;
    }
};