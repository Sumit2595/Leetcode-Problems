class Solution {
public:
    bool checkPrefix(string word1,string word2){
        int m=word1.size(),n=word2.size();
        if(m<n)
            return false;
        int i=0;
        while(i<n){
            if(word1[i] != word2[i])
                return false;
            i++;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence); 
  
        // To store individual words
        string word; 
        int totalPrefix=-1;
        int count=1;

        while (s >> word){
            if(checkPrefix(word,searchWord)){
                totalPrefix=count;
                break;
            }
            count++;
        }
        
       return totalPrefix;
    }
};