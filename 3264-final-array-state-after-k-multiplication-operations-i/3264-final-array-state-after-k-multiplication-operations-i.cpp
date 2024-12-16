#define pii pair<int,int>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k){
            int x=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            x=x*multiplier;
            cout<<x<<" ";
            pq.push({x,index});
            k--;
        }
         vector<int>ans(n);
        while(!pq.empty()){
            int x=pq.top().first;
            int index=pq.top().second;
            pq.pop(); 
            ans[index]=x;
        }
        return ans;
    }
};