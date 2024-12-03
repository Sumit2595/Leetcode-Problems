class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        for(auto num:nums){
            sum+=num;
            mp[num]++;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int outlier=nums[i];
            int remaining=sum-outlier;
            cout<<remaining<<" ";
            if(remaining % 2 == 0){
                if(mp[remaining/2] >=2)
                    ans=max(ans,outlier);
                if(mp[remaining/2] == 1 && outlier != remaining/2)
                    ans=max(ans,outlier);
            }
        }
        return ans;
    }
};