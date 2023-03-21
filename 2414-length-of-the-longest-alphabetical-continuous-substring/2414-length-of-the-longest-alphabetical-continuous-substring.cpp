class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.length();
        int ans=1;
        int last=s[0]-'a';
        int i=1;
        int length=1;
        while(i<n){
         if(last+1 == s[i]-'a'){
             last=s[i]-'a';
             length++;
             i++;
         } else{
             last=s[i]-'a';
             ans=max(ans,length);
             length=1;
             i++;
         } 
            ans=max(ans,length);
        }
        return ans;
    }
};