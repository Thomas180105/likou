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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        head = tail = new ListNode(1e5, nullptr);

        int k = lists.size();
        // if (k == 0) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (int i = 0; i < k; ++i)
        {
            if (lists[i] != nullptr) que.push(lists[i]);
        }

        cout<<que.size()<<'\n';

        while(!que.empty())
        {
            ListNode *cur = que.top();
            que.pop();

            tail = tail->next = new ListNode(cur->val);
            if (cur->next != nullptr) que.push(cur->next);
        }

        return head->next;
    }
private:
    ListNode *head;
    ListNode *tail;
    struct cmp{
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val;
        }
    };
};