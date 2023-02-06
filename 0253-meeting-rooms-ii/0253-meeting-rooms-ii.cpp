class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1;
        pq.push(nums[0][1]);
        for(int i=1;i<n;i++){
            if(!pq.empty() && pq.top()>nums[i][0]){
                pq.push(nums[i][1]);
            } else {
                ans=max(ans,(int)pq.size());
                while(!pq.empty() && pq.top()<=nums[i][0]){
                    pq.pop();
                }
                pq.push(nums[i][1]);
            }
            ans=max(ans,(int)pq.size());
        }
        return ans;
    }
};