class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int left=0,right=0,ans=0;
        while(right<n){
            mp[nums[right]]++;
            while(left<=right && mp.size() > 2){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
          
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};