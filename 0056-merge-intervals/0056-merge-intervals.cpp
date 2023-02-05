class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        int start=nums[0][0],end=nums[0][1];
        for(int i=1;i<n;i++){
            if(end>=nums[i][0] || end>=nums[i][1]){
                end=max(end,nums[i][1]);
            } else {
                ans.push_back({start,end});
                start=nums[i][0];
                end=nums[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};