class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        vector<int>left(n,0);
        vector<int>right(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0){
                left[0]=nums[0];
                ans=max(ans,left[i]);
            }
            else{
                if(nums[i] == 1){
                    left[i]=1+left[i-1];
                    ans=max(ans,left[i]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[i]=nums[i];
                ans=max(ans,right[i]);
            }
            else{
                if(nums[i] == 1){
                    right[i]=1+right[i+1];
                    ans=max(ans,right[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
            if(i==0){
                ans=max(ans,1+right[i+1]);
            } else if(i==n-1){
                ans=max(ans,1+left[i-1]);
            } else{
                ans=max(ans,left[i-1]+1+right[i+1]);
            }
            }      
        }
        return ans;
    }
};