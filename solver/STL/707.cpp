class MyLinkedList {
private:
    struct node{
        int val;
        node *prev;
        node *next;
        node(): val(-1), prev(nullptr), next(nullptr) {}
        node(int val): val(val), prev(nullptr), next(nullptr) {}
        node(int val, node *prev, node *next): val(val), prev(prev), next(next) {}
    };
    node *head;
    node *tail;
    int sz;
    void printList()
    {
        cout<<"the sz = "<<sz<<'\n';
        node *cur = head->next;
        while(cur != tail)
        {
            cout<<cur->val<<"-> ";
            cur = cur->next;
        }
        cout<<"end\n";
    }
public:
    MyLinkedList() {
        //实现一个带头尾节点的双链表
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }

    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        node *cur = head->next;
        for (int i = 0; i < index; ++i) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        ++sz;
        node *newNode = new node(val, head, head->next);
        newNode->next->prev = newNode;
        newNode->prev->next = newNode;
    }

    void addAtTail(int val) {
        ++sz;
        node *newNode = new node(val, tail->prev, tail);
        newNode->next->prev = newNode;
        newNode->prev->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz) return;
        ++sz;//先合法性检查之后再维护sz
        node *cur = head->next;
        for (int i = 0; i < index; ++i) cur = cur->next;
        node *newNode = new node(val, cur->prev, cur);
        newNode->next->prev = newNode;
        newNode->prev->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) return;
        --sz;
        node *cur = head->next;
        for (int i = 0; i < index; ++i) cur = cur->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */