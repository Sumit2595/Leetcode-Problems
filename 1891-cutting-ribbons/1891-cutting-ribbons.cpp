class Solution {
public:
    bool check(vector<int>& ribbons,int cut,int k){
        int n=ribbons.size();
        int count=0;
        for(int i=0;i<n;i++){
                count+=(ribbons[i]/cut);
        }
             
        return count>=k;
    }
    int maxLength(vector<int>& ribbons, int k) {
        int n=ribbons.size();
        int ans=0;
        int low=1,high=*max_element(ribbons.begin(),ribbons.end());
        while(low <= high){
            int mid=low+(high-low)/2;
            if(check(ribbons,mid,k)){
               low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return high;
    }
};