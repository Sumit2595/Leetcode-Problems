class Solution {
public:
    unordered_map<char,int>mp;
    bool isInCorrectOrder(string s,string t){
        int m=s.length(),n=t.length();
        int i=0,j=0;
        while(i<m && j<n){
            if(s[i]==t[j]){
                i++;j++;
                continue;
            }
            if(mp[s[i]]>mp[t[j]]){
                return false;
            }
           break;
        }
        if(j==n){
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string word1=words[i];
            string word2=words[i+1];
            if(word1 != word2){
                if(!isInCorrectOrder(word1,word2)){
                return false;
                }
            }
        }
        return true;
    }
};