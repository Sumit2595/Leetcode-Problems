class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int low=0;
        while(low+k-1<n){
            int diff=nums[low+k-1]-nums[low];
            ans=min(ans,diff);
            low++;
        }
        return ans;
    }
};