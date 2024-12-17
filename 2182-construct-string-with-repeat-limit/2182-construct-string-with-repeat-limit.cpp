class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) m[s[i]]++;
        priority_queue<pair<char,int>> pq;
        for(auto i: m){
            pq.push({i.first,i.second}); 
        }
        string ans="";
        while(!pq.empty()){
            char c1=pq.top().first;
            int id1=pq.top().second;
            pq.pop();
            int len=min(id1,repeatLimit);
            for(int i=0;i<len;i++){
                ans+=c1;
            }
            char c2;
            int id2=0;
            if(id1 - len > 0){
                if(!pq.empty()){
                c2=pq.top().first;
                id2=pq.top().second;
                    pq.pop();
                   ans+=c2;                       
                } else {
                    return ans;
                }
                pq.push({c1,id1 - len});
                if(id2-1>0)
                    pq.push({c2,id2-1});
            } 
        }
        return ans;
    }
};