class Solution {
public:
    bool check(vector<int>& nums,int capacity, int k){
        int sum=0,size=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=capacity){
                sum+=nums[i];
            } else {
                size++;
                if(size > k)
                    return false;
                sum=nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0,maxim=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxim=max(maxim,nums[i]);
        }
        int left=maxim,right=sum;
        while(left<right){
            int mid=left+(right-left)/2;
            if(check(nums,mid,k)){
                right=mid;
            } else {
                left=mid+1;
            }
        }
        return left;
    }
};