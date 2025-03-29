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
        if (!head) return head;

        int preNum = 1e5;
        ListNode *dummyHead = new ListNode(1e5, head);
        ListNode *preNode = dummyHead;
        ListNode *curNode = head;//可能删除第一个节点

        while(curNode)
        {
            if (curNode->next && curNode->next->val == curNode->val)
            {
                ListNode *delete_st = curNode;
                ListNode *delete_ed = curNode->next;
                while(delete_ed->next && delete_ed->next->val == curNode->val)
                {
                    ListNode *tmp = delete_ed->next;
                    delete delete_ed;//防止内存泄露
                    delete_ed = tmp;
                }

                curNode = preNode->next = delete_ed->next;
            }
            else
            {
                preNode = curNode;
                curNode = curNode->next;
            }
        }

        return dummyHead->next;
    }
};