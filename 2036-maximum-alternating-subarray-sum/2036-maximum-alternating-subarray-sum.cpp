class Solution {
public:
    #define ll long long
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
       
        return optimized(nums);
    }
    ll optimized(vector<int>& nums){
        ll n=nums.size();
        ll add=0,sub=0,prevSub=0;
        ll ans=nums[0];
        add=nums[0];
        for(int i=1;i<n;i++){
            sub=add-nums[i];
            add=max<ll>(prevSub+nums[i],1ll * nums[i]);
            ans=max({ans,add,sub});
            prevSub=sub;
        }
        return ans;
    }
};