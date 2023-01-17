class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        int len=1;
        int n=nums.size();
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<nums[i]){
                temp.push_back(nums[i]);
                len++;
            } else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return len;
    }
};