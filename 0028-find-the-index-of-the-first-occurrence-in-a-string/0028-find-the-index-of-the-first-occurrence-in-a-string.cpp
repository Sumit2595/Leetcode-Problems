class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length(),n=needle.length();
        if(n > m){
            return -1;
        }
        if(haystack == needle){
            return 0;
        }
        int i=0;
        while(i<m){
            string str=haystack.substr(i,n);
            if(str[0] != needle[0]){
                i++;
                continue;
            }
            if(str == needle){
                return i;
            }
            i++;
        }
        return -1;
    }
};