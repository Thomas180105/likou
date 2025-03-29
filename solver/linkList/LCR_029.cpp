/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head)
        {
            // cout<<"ha1\n";
            Node *newNode = new Node(insertVal, nullptr);
            newNode->next = newNode;
            return newNode;
        }

        //不知道是否多余，先写着
        if (head == head->next)
        {
            // cout<<"ha2\n";
            head->next = new Node(insertVal, head);
            return head;
        }

        //非空的时候，要么待插入值在区间内，要么插在最大值后面后者最小值前面
        //同时注意到有可能整个区间都是同一个数，这样可能循环，所以要探测一下循环
        //要插入，至少要维护当前两个节点，否则没办法插入
        Node *curNode = head;
        Node *nextNode = head->next;
        //找到一个位置，使得可以插入在curNode和nextNode之间
        while(nextNode != head)
        {
            if (curNode->val <= insertVal && nextNode->val >= insertVal) break;//找到
            else if (curNode->val > nextNode->val && (insertVal >= curNode->val || insertVal <= nextNode->val)) break;
            curNode = curNode->next;
            nextNode = nextNode->next;
        }

        // cout<<"the curNodeVal = "<<curNode->val<<", nextNodeVal = "<<nextNode->val<<'\n';
        //不通过break出来，则说明整个链表数字都一样，且与待插入节点一样，随便找一个位点插入新值即可
        Node *newNode = new Node(insertVal, nextNode);
        curNode->next = newNode;

        return head;
    }
};