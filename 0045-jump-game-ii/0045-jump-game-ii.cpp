class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size(),currJump=nums[0],maxJump=nums[0];
        if(n==1)
            return 0;
        int i=0,jumps=1;
        while(i<n-1){
            maxJump=max(maxJump,i+nums[i]);
            if(currJump == i){
                jumps++;
                currJump=maxJump;
            }
            i++;
        }
        return jumps;
    }
};