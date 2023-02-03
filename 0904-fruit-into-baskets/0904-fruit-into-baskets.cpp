class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int total=0;
        int n=fruits.size();
        int r=0,l=0,ans=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            while(l<=r && mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};