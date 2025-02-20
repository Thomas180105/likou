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
// 方法一：归并排序 空间复杂度O(1)，时间复杂度O(nlogn)，不过常数较大
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         ListNode* cur = head;
//         int cnt = 0;
//         while(cur) {++cnt; cur = cur->next;}
//         if (cnt <= 1) return head;

//         cur = head;
//         for(int i = 2; i <= cnt /2; ++i) cur = cur->next;
//         ListNode* newHead = cur->next;
//         cur->next = nullptr;

//         ListNode* pos1 = sortList(head);
//         ListNode* pos2 = sortList(newHead);

//         ListNode* dummyHead = new ListNode(-1, nullptr);
//         ListNode* resTail = dummyHead;
//         while(pos1 && pos2)
//         {
//             if (pos1->val <= pos2->val) {resTail = resTail->next = pos1; pos1 = pos1->next;}
//             else {resTail = resTail->next = pos2; pos2 = pos2->next;}
//         }
//         while(pos1) {resTail = resTail->next = pos1; pos1 = pos1->next;}
//         while(pos2) {resTail = resTail->next = pos2; pos2 = pos2->next;}

//         return dummyHead->next;
//     }
// };

// 方法二：异地排序 空间复杂度O(n)，时间复杂度O(nlogn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* tmp = head;
        while(tmp)
        {
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }

        sort(nums.begin(), nums.end());
        tmp = head;
        for (auto n : nums) {tmp->val = n; tmp = tmp->next;}
        return head;
    }
};