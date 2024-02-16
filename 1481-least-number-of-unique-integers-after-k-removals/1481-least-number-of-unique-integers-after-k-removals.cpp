#define pp pair<int,int>
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto a:arr){
            mp[a]++;
        }
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(k--){
            pp top=pq.top();
            pq.pop();
            top.first--;
            if(top.first>0){
                pq.push(top);
            }
        }
        return pq.size();
    }
};