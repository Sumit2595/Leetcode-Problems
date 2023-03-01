class Solution {
public:
    void outPlaceSort(vector<int>& nums,int low,int high,int mid){
        int l=low,r=mid+1,k=0,size=high-low+1;
        vector<int>temp(size);
        while(l<=mid && r<=high){
            temp[k++]=nums[l]<nums[r] ? nums[l++]:nums[r++];
        }
        while(l<=mid){
            temp[k++]=nums[l++];
        }
        while(r<=high){
           temp[k++]=nums[r++]; 
        }
        for(k=0;k<size;k++){
            nums[k+low]=temp[k];
        }
    }
    void mergeSort(vector<int>& nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        outPlaceSort(nums,low,high,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};