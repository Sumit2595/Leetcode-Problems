class WordDictionary {
public:
    WordDictionary *child[26] = {};
    bool isWord = false;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary *root = this;
        for(char &x : word) {
            int ind = x-'a';
            if(!root->child[ind]) root->child[ind] =  new WordDictionary();
            root = root->child[ind];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        return search(word,0,this);
    }
   
    bool search(string word,int pos,WordDictionary *root){
        if(pos == word.length())
            return root->isWord;
        char x=word[pos];
        if(x!='.'){
            return root->child[x-'a'] && search(word, pos+1, root->child[x-'a']);
        } else{
            for(int i=0;i<26;i++){
                if(root->child[i] && search(word,pos+1,root->child[i])){
                    return true;
                }
            }
            return false;
        }
        return root->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */