class Solution {
public:
    bool check(vector<int>& candies,int candy,long long k){
        int n=candies.size();
        long long count=0;
        for(int i=0;i<n;i++){
            long long candyDivided=candies[i]/candy;
            count+=candyDivided;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maximum=*max_element(candies.begin(),candies.end());
        int n=candies.size();
        int low=1,high=1e9+1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(candies,mid,k)){
                low=mid+1;
                cout<<mid<<" ";
                ans=mid;
            } else {
                  high=mid-1;
            }
        }
        return ans;
    }
};