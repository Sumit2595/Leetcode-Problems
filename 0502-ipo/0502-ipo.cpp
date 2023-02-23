class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = 0;
        if(profits.size() == 0 || capital.size() == 0)
            return ans;
        map<int,vector<int>> dict;
        int n=profits.size();
        for(int i=0;i<n;i++){
            dict[capital[i]].push_back(profits[i]);
        }
        priority_queue<int>pq;
        auto it=dict.begin();
        while(k){
            for(;it!=dict.end();++it){
                if(it->first > w)
                    break;
                vector<int>temp=it->second;
                for(int i=0;i<temp.size();i++){
                    pq.push(temp[i]);
                }
            }
            if(!pq.empty()){
                w+=pq.top();pq.pop();
                k--;
            } else {
                break;
            }
        }
        return w;
    }
};