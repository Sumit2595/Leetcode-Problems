#define piic pair<int,char>
class Solution {
public:    
    int minimumKeypresses(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        priority_queue<piic>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int first=9,second=9,third=8;
        int ans=0;
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        while(!pq.empty() && first >0){
            piic top=pq.top();
            pq.pop();
            ans+=(top.first);
            cout<<top.second<<" "<<top.first<<endl;
            first--;  
        }
        while(!pq.empty() && second >0){
            piic top=pq.top();
            pq.pop();
            ans+=(2*(top.first));
            second--;
            cout<<top.second<<" "<<2*top.first<<endl;
        }
        while(!pq.empty() && third >0){
            piic top=pq.top();
            pq.pop();
            ans+=(3*(top.first));
            third--;
            cout<<top.second<<" "<<3*top.first<<endl;
        }
        return ans;
    }
};