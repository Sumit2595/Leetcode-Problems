class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& qrs) {
        unordered_map<char,int>mp{{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
        int n=words.size();
        vector<int>sum(n,0);
        for(int i=0;i<n;i++){
            int l=0,r=words[i].size()-1;
            if(mp[words[i][l]] && mp[words[i][r]]){
                if(i==0){
                    sum[i]=1;
                } else {
                    sum[i]=1+sum[i-1];
                }
            } else {
                if(i!=0)
                sum[i]=sum[i-1];
            }
        }
        vector<int>ans;
        for(auto qr:qrs){
            if(qr[0] == 0){
                ans.push_back(sum[qr[1]]);
            } else {
                ans.push_back(sum[qr[1]]-sum[qr[0]-1]);
            }
        }
        return ans;
    }
};