class Solution {
public:
    bool makePalindrome(string s) {
       int n=s.length();
        int i=0,j=n-1;
        int operations=2;
        while(i<=j){
            if(s[i] != s[j]){
                if(!operations)
                    return false;
                operations--;
            } 
            i++;j--;
        }
        return true; 
    }
};