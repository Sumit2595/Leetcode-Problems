class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,int n,vector<int>&temp){
        if(n<=0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[n-1]);
        solve(nums,n-1,temp);
        temp.pop_back();
        solve(nums,n-1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        solve(nums,n,temp);
        return ans;
    }
};