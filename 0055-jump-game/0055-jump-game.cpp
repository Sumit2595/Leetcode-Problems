class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0){
            return n==1;
        }
        int maxJump=nums[0];
        for(int i=1;i<n;i++){
            if(maxJump<i)
                return false;
            maxJump=max(maxJump,nums[i]+i);
        }
        return true;
    }
};