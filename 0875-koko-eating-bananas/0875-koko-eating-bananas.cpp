class Solution {
public:
    bool check(vector<int>& piles, int h,int k){
        int sum=0;
        for(auto x:piles){
            sum+=x/k+(x%k!=0 ? 1:0);
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(auto p:piles){
            high=max(high,p);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(piles,h,mid)){
                high=mid;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};