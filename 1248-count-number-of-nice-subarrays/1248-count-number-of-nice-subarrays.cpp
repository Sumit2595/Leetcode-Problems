class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        int currOdd=0;
        for(int i=0;i<n;i++){
            currOdd+=(nums[i]%2)?1:0;
            if(currOdd == k)
                ans++;
            if(mp.count(currOdd-k))
              ans+=mp[currOdd-k];
            mp[currOdd]++;
        }
        return ans;
    }
};