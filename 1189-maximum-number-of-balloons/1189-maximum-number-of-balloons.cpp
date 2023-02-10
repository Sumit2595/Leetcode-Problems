class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        string str="balloon";
        for(auto x:text){
            mp[x]++;
        }
        int ans=INT_MAX;
        for(auto x:str){
            if(mp[x] == 0){
                return 0;
            }
            if(x=='l' || x=='o')
                ans=min(ans,mp[x]/2);
            else
                ans=min(ans,mp[x]);
        }
        return ans==INT_MAX?0:ans;
    }
};