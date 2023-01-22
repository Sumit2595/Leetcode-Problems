class Solution {
public:
    #define ll long long
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vec;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        ll currMax=0,ans=INT_MIN;
        for(int i=0;i<n;i++){
            currMax+=vec[i].second;
            pq.push(vec[i].second);
            if(pq.size() > k){
                ll minim=pq.top();
                pq.pop();
                currMax-=minim;
            }
            if(pq.size() == k){
                ans=max(ans,currMax * vec[i].first);
            }
        }
        return ans;
    }
};