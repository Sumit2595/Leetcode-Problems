class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        if(m>n){
            return false;
        }
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(auto x:s1){
            freq1[x]++;
        }
        for(int i=0;i<m;i++){
            freq2[s2[i]]++;
        }
        if(freq1 == freq2){
            return true;
        }
        int i=0;
        for(int j=m;j<n;j++){
            freq2[s2[j]]++;
           freq2[s2[i]]--;
           if(freq2[s2[i]] == 0){
               freq2.erase(s2[i]);
           }
           if(freq1 == freq2){
            return true;
            }
           i++;
        }
        return false;
    }
};