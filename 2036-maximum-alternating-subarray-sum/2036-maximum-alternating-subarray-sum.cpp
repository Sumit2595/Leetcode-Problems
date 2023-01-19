class Solution {
public:
    #define ll long long
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>add(n,0),sub(n,0);
        ll ans=nums[0];
        add[0]=nums[0];
        for(int i=1;i<n;i++){
            sub[i]=add[i-1]-nums[i];
            add[i]=max<ll>(sub[i-1]+nums[i],1ll * nums[i]);
            ans=max({ans,add[i],sub[i]});
        }
        return ans;
    }
};