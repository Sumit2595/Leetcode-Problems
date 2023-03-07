class Solution {
public:
    #define ll long long
    bool check(vector<int>& time, ll mid,int totalTrips){
        ll total=0;
        for(auto x:time){
            total+=mid/x;
        }
        return total>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low=1,high = 1LL * *max_element(time.begin(), time.end()) * totalTrips;
        for(auto x:time){
            if(high<x){
                high=x;
            }
        }
        while(low<high){
            ll mid=low+(high-low)/2;
            if(check(time,mid,totalTrips)){
                high=mid;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};