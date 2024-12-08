class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
          int n=events.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
         sort(events.begin(), events.end());   
         int maxSum=0,maxVal=0; 
        for(auto e:events){
            while(pq.size() && pq.top().first<e[0]){
                maxVal=max(maxVal,pq.top().second);
                pq.pop();
            }
            maxSum=max(maxSum,maxVal+e[2]);
          pq.push({e[1],e[2]});
        }
        return maxSum;
    }
};