class Trie {
private:
    struct node{
        char ch = 0;
        vector<node *> child;
        bool endFlag = false;

        node(): ch(0), child(26, nullptr) {}
        node(char c): ch(c), child(26, nullptr) {}
    };

    void clean(node *rt)
    {
        if (!rt) return;
        for (auto c : rt->child) if (c) clean(c);
        delete rt;
    }

    node *root;
public:
    Trie() {
        // node *root = new node(-1);
        root = new node(-1);
    }

    ~Trie(){
        clean(root);
    }

    void insert(string word) {
        node *cur = root;
        for (int i = 0, l = word.size(); i < l; ++i)
        {
            if (!cur->child[word[i] - 'a'])
            {
                cur->child[word[i] - 'a'] = new node(word[i]);
            }
            cur = cur->child[word[i] - 'a'];
        }
        cur->endFlag = true;
    }

    bool search(string word) {
        node *cur = root;
        for (int i = 0, l = word.size(); i < l; ++i)
        {
            if (!cur->child[word[i] - 'a']) return false;
            cur = cur->child[word[i] - 'a'];
        }
        return cur->endFlag;
    }

    bool startsWith(string prefix) {
        node *cur = root;
        for (int i = 0, l = prefix.size(); i < l; ++i)
        {
            if (!cur->child[prefix[i] - 'a']) return false;
            cur = cur->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */