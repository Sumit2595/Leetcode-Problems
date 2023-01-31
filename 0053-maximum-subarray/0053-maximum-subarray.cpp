class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],start=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            start=max(nums[i],start+nums[i]);
            ans=max(ans,start);
        }
        return ans;
    }
};