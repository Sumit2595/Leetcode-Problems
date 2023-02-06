class Solution {
public:
    bool check(vector<int>& piles, int h,int k){   
       long sum=0;
         for(auto x:piles)
         {   sum+=(x/k+(x%k==0?0:1));   
         }
          return sum<=h;
      }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal=0;
        for(auto p:piles){
            maxVal=max(maxVal,p);
        }
        int low=1,high=maxVal;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,h,mid)){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};