class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0,ans=INT_MAX;
        int right=0,left=0;
        while(right<n){
             while(right<n && sum<target){
                 sum+=nums[right];
                 right++;
             }
            while(left<=right && sum>=target){
                ans=min(ans,right-left);
                sum-=nums[left];
                left++;
            }
        }
        return ans == INT_MAX? 0 :ans;
    }
};