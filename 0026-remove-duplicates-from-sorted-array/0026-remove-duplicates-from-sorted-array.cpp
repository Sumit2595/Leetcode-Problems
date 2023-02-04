class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=0,i=1;
        int n=nums.size();
        if(n==1)
        return n;
        while(i<n){
            while(i<n && nums[start] == nums[i]){
                i++;
            }
            if(i>=n)
                break;
            start++;
            if(start<n){
                nums[start]=nums[i];
            }
        }
        return start+1;
    }
};