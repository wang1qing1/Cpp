class Trie {
public:
    unordered_set<string> prev;
    unordered_set<string> hash;
    Trie() {
    }
    
    void insert(string word) {
        hash.insert(word);
        string tmp;
        for(auto e:word)
        {
            tmp+=e;
            prev.insert(tmp);
        }
    }
    
    bool search(string word) {
        return hash.find(word)!=hash.end();
    }
    
    bool startsWith(string prefix) {
        return prev.find(prefix)!=prev.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */