class Solution {
public:
    int check(vector<int>& nums, int target){
        int start=0,end=0,n=nums.size();
        int sum=0,count=0;
        while(end<n){
            sum+=nums[end];
            while(sum > target){
                sum-=nums[start];
                start++;
            }
            count+=(end-start+1);
            end++;
        }
        return count;
    }
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int low=1,high=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid) < k){
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return low;
    }
};