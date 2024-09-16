class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int n=nums.size();
        int length=INT_MAX;
        int start=0,end=0;
        int sum=0;
        while(end<n){
            while(sum<target && end<n){
                sum+=nums[end];
                end++;
            }
            while(sum>=target && start<=end){
                length=min(length,end-start);
                sum-=nums[start];
                start++;
            }
        }
        
        return length == INT_MAX?0:length;
    }
};