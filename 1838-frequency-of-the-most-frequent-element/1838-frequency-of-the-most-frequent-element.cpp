class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=0;
        int ans=1;
        long sum=0;
        while(high<n){
            sum+=nums[high];
            while(sum+k < (long)nums[high] * (high-low+1)){
                 sum-=nums[low];
                 low++;
            }
            ans=max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};