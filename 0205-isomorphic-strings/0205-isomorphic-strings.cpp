class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        int n=s.length(),m=t.length();
        if(n!=m)
            return false;
        for(int i=0;i<n;i++){
            if(mp1.find(s[i])==mp1.end()){
                if(mp2.find(t[i]) != mp2.end())
                    return false;
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            } else {
                if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};