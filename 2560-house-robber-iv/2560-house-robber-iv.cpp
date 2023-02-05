class Solution {
public:
    int isPossible(vector<int>& nums, int k,int maxSum){
        int n=nums.size();
        int total=0;
        int lastIdx=1e9+1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxSum) continue;
            if(lastIdx+1 == i) continue;
            total++;
            lastIdx = i;
        }
        return total>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=1e9+1,res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,k,mid)){
                res=mid;
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return res;
    }
};