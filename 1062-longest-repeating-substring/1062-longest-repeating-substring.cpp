class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_map<string,int>mp;
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            string temp="";
            temp+=s[i];
            if(mp.find(temp)!=mp.end()){
                    ans=max(ans,(int)temp.size());
                } else{
                    mp[temp]++;
                }
            for(int j=i+1;j<n;j++){
                temp+=s[j];
                if(mp.find(temp)!=mp.end()){
                   ans=max(ans,(int)temp.size());
                } else{
                    mp[temp]++;
                }
            }
        }
        return ans;
    }
};