class Solution {
public:
    int binarySearch(vector<int>nums,int l,int r,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            } else if(nums[mid]<target){
                l=mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        int pivot=low;
        int left=binarySearch(nums,0,pivot-1,target);
        int right=binarySearch(nums,pivot,n-1,target);
        if(left!=-1){
            return left;
        } 
        if(right!=-1)
            return right;
        return -1;
    }
};