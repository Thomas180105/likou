class LRUCache {
private:
    struct node{
        int key;
        int value;
        node *prev = nullptr;
        node *nxt = nullptr;
        node() {}
        node(int k, int v): key(k), value(v) {}
    };

    node *head;
    node *tail;
    int siz = 0, capacity;
    unordered_map<int, node*> hash;

// 哈希表中的delete不封装在这里
    void removeNode(node *cur)
    {
        cur->prev->nxt = cur->nxt;
        cur->nxt->prev = cur->prev;
        cur->prev = cur->nxt = nullptr;
    }

    node* removeTail()
    {
        node *res = tail->prev;
        removeNode(res);
        return res;
    }

//将一个孤立节点加在第一个
    void addToHead(node *cur)
    {
        cur->nxt = head->nxt;
        head->nxt->prev = cur;
        head->nxt = cur;
        cur->prev = head;
    }

    void moveToHead(node *cur)
    {
        removeNode(cur);
        addToHead(cur);
    }

public:
    LRUCache(int c) {
        head = new node();
        tail = new node();
        head->nxt = tail;
        tail->prev = head;
        capacity = c;
        siz = 0;
    }

    ~LRUCache()
    {
        node *cur = head;
        node *nxt = cur;
        while(cur)
        {
            nxt = cur->nxt;
            delete cur;
            cur = nxt;
        }
    }

    int get(int key) {
        if (!hash.count(key)) return -1;
        node *res = hash[key];
        moveToHead(res);
        return res->value;
    }

    void put(int key, int value) {
        if (hash.count(key))
        {
            node *cur = hash[key];
            cur->value = value;
            moveToHead(cur);
        }
        else
        {
            // cout<<"we are insert ("<<key<<", "<<value<<")\n";
            ++siz;
            node *new_node = new node(key, value);
            hash[key] = new_node;
            addToHead(new_node);
            if (siz > capacity)
            {
                // cout<<"oppo! now siz = "<<siz<<" capacity = "<<capacity<<'\n';
                --siz;
                node *to_delete = removeTail();
                hash.erase(to_delete->key);
                // cout<<"we are deleting ("<<to_delete->key<<", "<<to_delete->value<<")";
                bool f = hash.count(to_delete->key);
                // cout<<" f = "<<f<<'\n';
                delete to_delete;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */