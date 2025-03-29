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
private:
    struct cmp{
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //两个思路：两路合并用分治来做；优先级队列每次k个数选最小
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> que;//不变量：里面放的指针都不是空指针
        ListNode* head = new ListNode(-1, nullptr);
        ListNode* tail = head;
        for(auto cur: lists)
        {
            if (cur == nullptr) continue;
            que.push(cur);
        }
        while(!que.empty())
        {
            auto cur = que.top();
            que.pop();
            tail = tail->next = cur;
            if (cur->next) que.push(cur->next);
        }
        return head->next;
    }
};