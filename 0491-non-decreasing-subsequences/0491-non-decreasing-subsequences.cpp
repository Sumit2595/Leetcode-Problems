class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    vector<int>temp;
    void solve(vector<int>nums,int idx,int last){
        if(idx>=nums.size()){
            if(temp.size()>=2){
                st.insert(temp);
            }
            return;
        }
        if(nums[idx]>=last){
            temp.push_back(nums[idx]);
            solve(nums,idx+1,nums[idx]);
            temp.pop_back();
        }
        solve(nums,idx+1,last);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,0,INT_MIN);
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};