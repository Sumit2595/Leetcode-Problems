class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto num:nums)
            mp[num]++;
        for(int i=0;i<n;i++){
            if(nums[i] == 0 && mp[0] >= 2){
                return true;
            } else if(nums[i] == 0 && mp[0] <= 1){
                continue;
            }          
            int num=2*nums[i];
            if(mp.find(num)!=mp.end()){
                cout<<num<<" "<<nums[i];
                return true;
            }
        }
        return false;
    }
};