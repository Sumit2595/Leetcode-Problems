class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
       vector<int>minutes(timePoints.size());
        int n=timePoints.size();
       for(int i=0;i<n;i++){
           string time=timePoints[i];
           int h=stoi(time.substr(0,2));
           int m=stoi(time.substr(3));
           minutes[i]=h*60+m;
       }
        sort(minutes.begin(), minutes.end());
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ans=min(ans,minutes[i+1]-minutes[i]);
        }
        ans=min(ans,24*60 - (minutes[n-1]-minutes[0]));
        return ans;
    }
};