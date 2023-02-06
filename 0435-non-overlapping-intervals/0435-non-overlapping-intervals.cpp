class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
     priority_queue<pair<int,int>>pq;
        int n=nums.size();
        if(n==1)
            return 0;
        int ans=0;
        sort(nums.begin(),nums.end());
        pq.push({nums[0][1],nums[0][0]});
        for(int i=1;i<n;i++){
           if(pq.top().first>nums[i][0]){
               if(pq.top().first > nums[i][1]){
                  pq.pop();
                  pq.push({nums[i][1],nums[i][0]});
               }
               ans++;
           } else{
               pq.push({nums[i][1],nums[i][0]});
           }
        }
        return ans;
    }
};