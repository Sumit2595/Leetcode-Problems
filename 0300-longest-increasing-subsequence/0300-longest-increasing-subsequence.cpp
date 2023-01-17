class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
             if(nums[i]>nums[j]){
                dp[i]=max(1+dp[j],dp[i]);
                }    
            }
        }
        int res=0;
        for(auto val:dp){
            res=max(res,val);
        }
        return res;
    }
};