class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int low=0,high=k-1;
        while(high<n){
            int diff=nums[high]-nums[low];
            ans=min(ans,diff);
            low++;
            high++;
        }
        return ans;
    }
};