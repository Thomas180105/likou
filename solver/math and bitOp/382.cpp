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
    Solution(ListNode* head): head(head) {

    }

    int getRandom() {
        ListNode *cur = head;//ensure that len(LinkList)>=1
        ListNode *ans = head;
        // if (ans == nullptr) cout<<"warning in intialize!\n";
        int i = 1;
        while(cur)
        {
            if (rand() % i++ == 0) ans = cur;
            cur = cur->next;
        }
        // if (ans == nullptr) cout<<"warning!\n";
        return ans->val;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */