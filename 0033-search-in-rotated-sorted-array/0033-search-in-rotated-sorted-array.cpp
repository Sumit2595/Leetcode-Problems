class Solution {
public:
    int bsearch(vector<int>& nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
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
        int left=bsearch(nums,0,pivot-1,target);
        int right=bsearch(nums,pivot,n-1,target);
        if(left!=-1)
            return left;
        if(right!=-1)
            return right;
        return -1;
    }
};