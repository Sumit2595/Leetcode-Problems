class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int low,high;
        for(int i=0;i<n;i++){
            low=i+1,high=n-1;
            int rem=target-nums[i];
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid] == rem && i!=mid){
                    return {i+1,mid+1};
                } else if(nums[mid] > rem){
                    high=mid-1;
                } else {
                    low=mid+1;
                }
            }
        }
        return {};
    }
};