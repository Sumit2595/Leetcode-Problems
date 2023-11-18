class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        long curr=0;
        int right=0;
        int freq=0;
        int n=nums.size();
        while(right<n){
            long target=nums[right];
            curr+=target;
            if((right-left+1) * target - curr > k){
                curr-=nums[left];
                left++;
            }
            freq=max(freq,right-left+1);
            right++;
        }
        return freq;
    }
};