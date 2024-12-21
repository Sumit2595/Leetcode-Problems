class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        int i=0,j=2;
        int n=nums.size();
        while(j<n){
            int num1=nums[i] + nums[j];
            if(2*num1 == nums[j-1])
                ans++;
            i++;
            j++;
        }
        return ans;
    }
};