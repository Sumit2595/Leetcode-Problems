class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>twoPower{1};
        for(int i=0;i<n;i++){
            twoPower.push_back((twoPower.back() * 2)%mod);
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1,ans=0;
        while(i<=j){
            if(nums[i]+nums[j]>target){
                j--;
            } else {
                int rem=j-i;
                ans=(ans+twoPower[rem])%mod;
                i++;
            }
        }
        return ans;
    }
};