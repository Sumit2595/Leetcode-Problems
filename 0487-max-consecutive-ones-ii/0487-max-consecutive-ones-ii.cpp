class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0,ans=0,zeros=0;
        while(right<n){
            if(nums[right] == 0){
                zeros++;
            }
            while(zeros == 2){
                if(nums[left] == 0)
                {  zeros--;
                }
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};