class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=nums[0];
        int boats=0;
        int low=0,high=n-1;
        while(low<=high){
            int load=nums[low]+nums[high];
            if(load<=limit){
                boats++;
                low++;
                high--;
            } else {
             boats++;
                high--;
            }
        }
        return boats;
    }
};