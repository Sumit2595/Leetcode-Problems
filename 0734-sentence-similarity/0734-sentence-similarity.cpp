class Solution {
public:
    unordered_map<string,set<string>>mp;
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& similarPairs) {
        int m=s1.size(),n=s2.size();
        if(m!=n)
            return false;
        for(auto x:similarPairs){
            mp[x[0]].insert(x[1]);
            mp[x[1]].insert(x[0]);
        }
        for(int i=0;i<n;i++){
            if(s1[i] == s2[i])
                continue;
            auto st1=mp[s1[i]];
            auto st2=mp[s2[i]];
            if(st1.find(s2[i])!=st1.end() || st2.find(s1[i])!=st2.end())
                continue;
            return false;
        }
        return true;
    }
};