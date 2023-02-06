class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       for(int i=n;i<2*n;i++){
           nums[i]=(nums[i] * 1024) + nums[i-n];
       }
        int idx=0;
       for(int i=n;i<2*n;i++,idx+=2){
           nums[idx]=nums[i]%1024;
           nums[idx+1]=nums[i]/1024;
       }
        return nums;
    }
};