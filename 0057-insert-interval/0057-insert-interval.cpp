class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int j=1;
        int i=0;
        while(j<n){
           if(intervals[i][1]>=intervals[j][0]){
               intervals[i][1]=max(intervals[j][1],intervals[i][1]);
            } else {
               i++;
               intervals[i]=intervals[j];
           }
            j++;
        }
        intervals.erase(intervals.begin()+i+1,intervals.end());
        return intervals;
    }
};