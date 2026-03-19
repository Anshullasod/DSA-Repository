class Node{
    public:
    bool isend;
    unordered_map<char,Node*> children;
    Node()
    {
        isend=false;
    }
};
class Trie {
public: 
    Node* root;
    Trie() {
        root=new Node();    
    }
    
    void insert(string word) {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {   if(!temp->children.count(word[i]))
            {temp->children[word[i]]=new Node();}
            temp=temp->children[word[i]];
        }
        temp->isend=true;
    }
    
    bool search(string word) {
         Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->children.count(word[i]))
            {
                return false;
            }
            temp=temp->children[word[i]];
            
        }
        return temp->isend;
    }
    
    bool startsWith(string prefix) {
          Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->children.count(prefix[i]))
            {
                return false;
            }
            temp=temp->children[prefix[i]];
            
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