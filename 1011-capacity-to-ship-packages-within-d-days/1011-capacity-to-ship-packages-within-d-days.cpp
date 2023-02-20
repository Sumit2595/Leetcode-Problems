class Solution {
public:
    bool check(vector<int>& nums,int days,int capacity){
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
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxim=weights[0];
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            maxim=max(maxim,weights[i]);
        }
        int left=maxim,right=sum;
        while(left<right){
            int mid=left+(right-left)/2;
            if(check(weights,days,mid)){
                right=mid;
            } else {
                left=mid+1;
            }
        }
        return left;
    }
};