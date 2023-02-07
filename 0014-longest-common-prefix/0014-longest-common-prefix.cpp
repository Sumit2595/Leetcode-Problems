class Solution {
public:
    string common(string s,string t){
        string str="";
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i] != t[j]){
                break;
            }
            str+=s[i];
            i++;j++;
        }
        return str;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        string ans="";
        ans=common(strs[0],strs[1]);
        for(int i=2;i<n;i++){
            ans=common(ans,strs[i]);
        }
        return ans;
    }
};