class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
             continue;
            swap(nums[i],nums[res]);
            res++;
        }
    }
};