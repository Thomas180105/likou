/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        bool a_flag = false, b_flag = false;

        while(true)
        {
            if (a == b) return a;
            if (a) a = a->next;
            else {
                if (a_flag) return nullptr;
                else a = headB;
            }

            if (b) b = b->next;
            else{
                if (b_flag) return nullptr;
                else b = headA;
            }

            //注，其实可以直接 a = a ? a->next : headB; b = b ? b->next : headA;而不需判断flasg
        }
    }
};//
// Created by Lenovo on 2024/12/30.
//
