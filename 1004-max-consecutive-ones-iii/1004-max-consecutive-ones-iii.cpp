class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int r=0,l=0,maxCount=0,ans=0;
        int zeros=0,ones=0;
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }
            while(l<=r && zeros>k){
                if(nums[l] == 0){
                  zeros--;   
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};