class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        map<int,int>mp{{nums[0],1}};
        int left=0,right=0,length=0;
        while(right<n){
            int mx=(mp.begin())->first;
            int mn=(--mp.end())->first;
            if(abs(mx-mn) <= limit){
                length=max(length,right-left+1);
                right++;
                if(right<n)
                 mp[nums[right]]++;
            } else {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }
        }
        return length;
    }
};