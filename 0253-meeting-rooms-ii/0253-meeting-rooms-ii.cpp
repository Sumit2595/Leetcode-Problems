class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        int rooms=1;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            int last=pq.top();
            int sz=pq.size();
            rooms=max(rooms,sz);
            if(!pq.empty() && last<=intervals[i][0]){
                pq.pop();
            } 
            pq.push(intervals[i][1]);
            sz=pq.size();
            rooms=max(rooms,sz);
        }
        int sz=pq.size();
        rooms=max(rooms,sz);
        return rooms;
    }
};