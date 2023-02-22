class Solution {
public:
    bool check(vector<int>& nums,int capacity,int days){
        int d=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=capacity){
                sum+=nums[i];
            } else {
                d++;
                sum=nums[i];
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int n=nums.size();
        int maxim=nums[0],sum=0;
        for(auto x:nums){
            sum+=x;
            maxim=max(x,maxim);
        }
        int low=maxim,high=sum;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,days)){
                high=mid;
            } else {
                low=mid+1;
            } 
        }
       return low; 
    }
};