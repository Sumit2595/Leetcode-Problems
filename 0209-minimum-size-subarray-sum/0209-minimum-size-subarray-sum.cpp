class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int front=0,rear=0;
        int sum=0;
        int ans=INT_MAX;
        int n=nums.size();
        while(rear<n){
            while(sum<target && rear<n){
                sum+=nums[rear];
                rear++;
            }
            while(sum>=target && front<=rear){
               ans=min(ans,rear-front);
                sum-=nums[front];
                front++;
            }
        }
        return ans == INT_MAX?0:ans;
    }
};