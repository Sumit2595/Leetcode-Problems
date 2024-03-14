class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0,count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum == goal)
                count++;
            if(mp.find(sum-goal) != mp.end())
                count+=mp[sum-goal];
            mp[sum]++;
        }
        return count;
    }
};