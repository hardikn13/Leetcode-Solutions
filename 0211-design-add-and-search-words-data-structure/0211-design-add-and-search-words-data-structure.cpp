class Node {
    public:

    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        if(links[ch - 'a'] != NULL)
            return true;
        return false;
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node -> containsKey(word[i]))
                node -> put(word[i], new Node());

            node = node -> get(word[i]);
        }

        node -> setEnd();
    }
    
    bool search(string word) {
        return searchInNode(word, root);
    }
    
    bool searchInNode(const string& word, Node* node) {
        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if(ch == '.')
            {
                for(int j = 0; j < 26; j++)
                {
                    if(node->links[j] && searchInNode(word.substr(i + 1), node->links[j]))
                        return true;
                }

                return false;
            }
            else
            {
                if(!node->containsKey(ch))
                    return false;
                node = node->get(ch);
            }
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!node -> containsKey(prefix[i]))
                return false;
            
            node = node -> get(prefix[i]);
        }

        return true;
    }
};

class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */