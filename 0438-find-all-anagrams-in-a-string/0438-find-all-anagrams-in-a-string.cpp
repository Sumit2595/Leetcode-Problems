class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        vector<int>ans;
        for(int i=0;i<p.length();i++)
            mp2[p[i]]++;
        int i=0,j=0,n=s.length();
        while(j<n){
            mp1[s[j]]++;
            while(i<j && j-i+1>p.length()){
                mp1[s[i]]--;
                if(mp1[s[i]] == 0){
                    mp1.erase(s[i]);
                }
                i++;
            }
            if(mp1 == mp2){
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};