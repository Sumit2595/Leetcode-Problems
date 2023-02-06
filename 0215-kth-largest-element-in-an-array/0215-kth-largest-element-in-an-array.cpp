class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        k--;
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid == k){
                return nums[mid];
            } else if(mid > k){
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return -1;
    }
};