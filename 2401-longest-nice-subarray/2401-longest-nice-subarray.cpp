class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int used=0;
        int j=0,res=1,i=0;
        while(i<n){
            while((used&nums[i]) != 0){
                used^=nums[j];
                j++;
            }
            used|=nums[i];
            res=max(res,i-j+1);
            i++;
        }
        return res;
    }
};