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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> nums;
        ListNode *curNode = head;
        while(curNode)
        {
            ListNode *tmp = curNode->next;
            nums.push_back(curNode->val);
            // delete curNode; 似乎不能修改原来指针，那就不管内存泄露了，估计是测评程序中会继续使用head？
            curNode = tmp;
        }

        for (auto t : nums) cout<<t<<" ";
        cout<<"\n";

        ListNode *dunmmyHead = new ListNode(-1);
        curNode = dunmmyHead;
        int len = nums.size(), st = 0;
        while(st < len)
        {
            int ed = -1, sum = 0;
            for (int j = st; j < len; ++j)
            {
                sum += nums[j];
                if (sum == 0) ed = j;
            }
            if (ed == -1)
            {
                curNode = curNode->next = new ListNode(nums[st]);
                ++st;
            }
            else st = ed + 1;
        }

        return dunmmyHead->next;
    }
};