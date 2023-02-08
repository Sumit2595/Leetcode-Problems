class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=n-1,i=0;
        while(i<=j){
            if(nums[i]==val){
                while(j>=0 && nums[j]==val){
                    j--;
                }
                if(i>j) return i;
                swap(nums[i],nums[j]);
                j--;
            }
            i++;
        }
        return i;
    }
};