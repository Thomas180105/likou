class WordDictionary {
private:
    struct node{
        vector<node*> children;
        bool isEnd;
        node () : isEnd(false), children(26, nullptr) {}
    };
    node *root;

    bool dfs(node* cur, const string &str, int pos, int sLen)
    {
        if (pos == sLen) return cur->isEnd;

        if (str[pos] != '.')
        {
            if (!cur->children[str[pos] - 'a']) return false;
            return dfs(cur->children[str[pos] - 'a'], str, pos + 1, sLen);
        }
        else
        {
            for (int i = 0; i < 26; ++i)
            {
                if (cur->children[i] && dfs(cur->children[i], str, pos + 1, sLen)) return true;
            }
            return false;
        }
    }
public:
    WordDictionary() {
        root = new node();
    }

    void addWord(string word) {
        node* cur = root;
        for (int i = 0, len = word.size(); i < len; ++i)
        {
            if (!cur->children[word[i] - 'a']) cur->children[word[i] - 'a'] = new node();
            cur = cur->children[word[i] - 'a'];
        }
        cur->isEnd = true;
        // cout<<"we add "<<word<<"\n";
    }

    bool search(string word) {
        // cout<<"we are now searching for "<<word<<'\n';
        return dfs(root, word, 0, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */