class Solution {
public:
    int shortestWay(string s, string t) {
        int i=0,j=0;
        int res=0;
        while(i<t.size() && res<=i){
            while(j<s.size() && t[i]!=s[j]){
                j++;
            }
            if(j==s.size()){
                res++;
                j=0;
            } else{
                i++;
                j++;
            }
        }
        return res<=i?res+1:-1;
    }
};