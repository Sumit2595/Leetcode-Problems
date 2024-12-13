#define ll long long 
#define pii pair<int,int>
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        unordered_map<int,int>marked;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        ll score=0;
        while(!pq.empty()){
            auto smallest=pq.top();
            pq.pop();
            int element=smallest.first;
            int index=smallest.second;
            if(marked.find(index)!=marked.end()){
                continue;
            }
           score+=element;
           if(index-1>=0)
               marked[index-1]++;
            if(index+1<n)
                marked[index+1]++; 
        }
        return score;
    }
};