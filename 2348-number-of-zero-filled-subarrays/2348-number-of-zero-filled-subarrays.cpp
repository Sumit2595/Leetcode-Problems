class Solution {
public:
    #define ll long long
    ll getTotal(ll n){
        return n*(n+1)/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            ll total=0;
            if(nums[i]==0){
                while(i<n && nums[i]==0){
                    total++;
                    i++;
                }
                ans+=getTotal(total);
            } else {
                i++;
            }
        }
        return ans;
    }
};