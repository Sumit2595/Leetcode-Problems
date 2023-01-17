class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubarray=nums[0];
        int start=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            start=max(nums[i],start+nums[i]);
            maxSubarray=max(maxSubarray,start);
        }
        return maxSubarray;
    }
};