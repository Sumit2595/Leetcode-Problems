class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
         priority_queue<int>pq;
        int minim=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
            nums[i]=nums[i]*2;
            }
            pq.push(nums[i]);
            minim=min(minim,nums[i]);
        }
        int ans=INT_MAX;
        while(pq.top()%2==0)
       {   int currMax=pq.top();
            pq.pop();
             pq.push(currMax/2);
            minim=min(minim,currMax/2);
           ans=min(ans,pq.top()-minim);
       }
        return ans;
    }
};