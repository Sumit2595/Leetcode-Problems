class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int diff=k-nums[i];
            if(mp[diff] > 0){
                ops++;
                mp[diff]--;
            } else {
                mp[nums[i]]++;
            }
        }
        return ops;
    }
};