class Trie {
public:
    class Node{
        public:
          Node* child[26];
          bool isEnd=false;  
    };
     Node* root;   
    Trie() {
       root=new Node(); 
    }
    
    void insert(string word) {
        Node* curr=root;
        for(auto ch:word){
            if(!curr->child[ch-'a']){
                curr->child[ch-'a']=new Node();
            }
            curr=curr->child[ch-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(auto ch:word){
            if(!curr->child[ch-'a']){
                return false;
            }
           curr=curr->child[ch-'a']; 
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(auto ch:prefix){
            if(!curr->child[ch-'a']){
                return false;
            }
           curr=curr->child[ch-'a']; 
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