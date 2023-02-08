class Solution {
public:
    #define pp pair<int,int>
    unordered_map<int,int>mp;
    int solve(vector<int>& nums,int idx,int n){
        if(idx>=n-1){
            return 0;
        }
        if(nums[idx] == 0){
            return INT_MAX/2;
        }
        if(mp.find(idx)!=mp.end()){
            return mp[idx];
        }
        int mn=INT_MAX;
        for(int j=1;j<=nums[idx] && j<n;j++){
            int temp=1+solve(nums,idx+j,n);
            mn=min(mn,temp);
        }
        return mp[idx]=mn;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n);
    }
};