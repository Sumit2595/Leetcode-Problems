class Solution {
public:
    bool isPalindrome(string s) {
        string word="";
        for(auto ch:s){
            if(isalnum(ch)){
                word+=tolower(ch);
            }
        }
        int low=0,high=word.size()-1;
        while(low<high){
           if(word[low] != word[high])
               return false;
            low++;
            high--;
        }
        return true;
    }
};