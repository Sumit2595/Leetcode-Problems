class Solution {
public:
    int kadanes(vector<int>nums){
        int curr=nums[0];
        int maxSubArray=nums[0];
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            maxSubArray=max(maxSubArray,curr);
        }
        return maxSubArray;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int x=kadanes(nums);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        int z=kadanes(nums);
        int y=sum+z;
        if(y == 0)
            return x;
        return max(x,y);
    }
};