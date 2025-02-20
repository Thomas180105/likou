//key->node
//node中 freq unordered_map<int> vals;
//现在关键问题是如何处理平局时去除最久未使用的键，这里要维护一个时序信息，用链表+哈希来维护似乎就行了？
//key->blockNode*
//unordered_map<int, blockNode*> key2block;
//blockNode中 (1)int (2)freq unordered_map<int, listNode*> key2node; (3)listNode* head, tail;
//如果直接把freq放在listNode中，移除blockNode这个中间层的话，无法O（1）时间内找到要删除的键值对
class LFUCache {
private:
    struct listNode{
        int k;
        int val;
        listNode* prev;
        listNode* next;
        listNode(): k(-1), val(-1), prev(nullptr), next(nullptr) {}
        listNode(int k, int val): k(k), val(val), prev(nullptr), next(nullptr) {}
        listNode(int k, int val, listNode* prev, listNode* next): k(k), val(val), prev(prev), next(next) {}
    };
    struct blockNode{
        int freq;
        blockNode* prev;
        blockNode* next;

        unordered_map<int, listNode*> key2node;
        listNode* head;
        listNode* tail;
        blockNode(): freq(-1), prev(nullptr), next(nullptr)
        {
            head = new listNode();
            tail = new listNode();
            head->next = tail;
            tail->prev = head;
        }
        blockNode(int freq, blockNode* prev, blockNode* next): freq(freq), prev(prev), next(next)
        {
            head = new listNode();
            tail = new listNode();
            head->next = tail;
            tail->prev = head;
        }
        ~blockNode()
        {
            listNode* tmp;
            while(head)
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }

        //被用到的就移动到head上
        //删除一个指定节点，增加一个节点，移动一个节点到头节点
        void delNode(listNode* node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = node->prev = nullptr;
        }
        void addToHead(listNode* node)
        {
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
        }
        void moveToHead(listNode* node)
        {
            delNode(node);
            addToHead(node);
        }
        bool empty() {return head->next == tail;}
    };

    void delBlock(blockNode* curBlock)
    {
        curBlock->prev->next = curBlock->next;
        curBlock->next->prev = curBlock->prev;
        delete curBlock;
    }

    void addNewBlock(int freq, blockNode* curBlock, blockNode*& newBlock)
    {
        newBlock = new blockNode(freq, curBlock, curBlock->next);
        newBlock->prev->next = newBlock;
        newBlock->next->prev = newBlock;
    }

    void debug()
    {
        blockNode* curBlock = head->next;
        cout<<"*************\n";
        while(curBlock != tail)
        {
            listNode* node = curBlock->head->next;
            cout<<"freq = "<<curBlock->freq<<" ";
            while(node != curBlock->tail)
            {
                cout<<"("<<node->k<<", "<<node->val<<") ";
                node = node->next;
            }
            curBlock = curBlock->next;
        }
        cout<<'\n';
    }


//unordered_map<int, blockNode*> key2block;
//blockNode中 (1)int (2)freq unordered_map<int, listNode*> key2node; (3)listNode* head, tail;
//listNode中 int val, listNode* prev next
    unordered_map<int, blockNode*> key2block;
    blockNode* head;
    blockNode* tail;
    int sz;
    int capacity;
public:
    LFUCache(int capacity): sz(0), capacity(capacity)
    {
        head = new blockNode();
        tail = new blockNode();
        head->next = tail;
        tail->prev = head;
    }

    ~LFUCache()
    {
        blockNode* tmp;
        while(head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int get(int key) {
        if (!key2block.count(key)) return -1;

        int res = key2block[key]->key2node[key]->val;

        //大映射：key映射到的block 大链表：新的block是否已经存在？旧的block是否要消亡？
        //小链表：两个链表的变动,小映射：node在对应两个block中的映射

        //新的block是否已经存在？
        blockNode* curBlock = key2block[key];
        blockNode* newBlock;
        if (curBlock->next->freq == curBlock->freq + 1) newBlock = curBlock->next;
        else addNewBlock(curBlock->freq + 1, curBlock, newBlock);

        //key映射到的block
        key2block[key] = newBlock;
        //维护两个block的信息
        listNode* curNode = curBlock->key2node[key];
        curBlock->key2node.erase(key);
        newBlock->key2node[key] = curNode;
        curBlock->delNode(curNode);
        newBlock->addToHead(curNode);

        //旧的block是否要消亡
        if (curBlock->empty()) delBlock(curBlock);

        // cout<<"after get "<<key<<'\n';
        // debug();

        return res;
    }

    void put(int key, int value) {
        blockNode* curBlock;
        if (sz == capacity && !key2block.count(key))
        {
            curBlock = head->next;
            listNode* curNode = curBlock->tail->prev;
            //大映射 小映射 小链表
            key2block.erase(curNode->k);
            curBlock->key2node.erase(curNode->k);
            curBlock->delNode(curNode);
            delete curNode;
            //大链表
            if (curBlock->empty()) delBlock(curBlock);

            // cout<<"after capacity check\n";
            // debug();
            --sz;
        }

        //大映射 大链表 小映射 小链表
        if (key2block.count(key))
        {
            curBlock = key2block[key];
            //大链表
            blockNode* newBlock;
            if (curBlock->next->freq == curBlock->freq + 1) newBlock = curBlock->next;
            else addNewBlock(curBlock->freq + 1, curBlock, newBlock);
            //大映射 小映射 小链表
            key2block[key] = newBlock;
            listNode* curNode = curBlock->key2node[key];
            curNode->val = value;
            --sz;
            curBlock->key2node.erase(key);
            newBlock->key2node[key] = curNode;
            curBlock->delNode(curNode);
            newBlock->addToHead(curNode);
            if (curBlock->empty()) delBlock(curBlock);
        }
        else
        {
            //大链表
            if (head->next->freq == 1) curBlock = head->next;
            else addNewBlock(1, head, curBlock);
            //大映射 小映射 小链表
            key2block[key] = curBlock;
            listNode* curNode = new listNode(key, value);
            curBlock->key2node[key] = curNode;
            curBlock->addToHead(curNode);
        }
        ++sz;

        // cout<<"after put "<<"("<<key<<", "<<value<<"), now the sz is "<<sz<<'\n';
        // debug();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */