class Solution {
public:
    #define ll long long
    ll waysToChoose(ll n){
        return n*(n-1)/2;
    }
    long long countBadPairs(vector<int>& nums) {
        unordered_map<ll,ll>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
        ll total = waysToChoose(n);
        ll pairs=0;
        for(auto x:mp){
            ll y=x.second;
            pairs+=waysToChoose(y);
        }
        return total-pairs;
    }
};