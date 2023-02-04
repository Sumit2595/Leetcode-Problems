class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.length();
        int n=p.length();
        if(n>m){
            return {};
        }
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        vector<int>ans;
        for(auto x:p){
            freq2[x]++;
        }
        for(int i=0;i<n;i++){
            freq1[s[i]]++;
        }
        if(freq1 == freq2){
            ans.push_back(0);
        }
        int l=0;
        for(int i=n;i<m;i++){
            freq1[s[i]]++;
            freq1[s[l]]--;
            if(freq1[s[l]] == 0){
                freq1.erase(s[l]);
            }
            l++;
            if(freq1 == freq2){
            ans.push_back(l);
            }
        }
        return ans;
    }
};