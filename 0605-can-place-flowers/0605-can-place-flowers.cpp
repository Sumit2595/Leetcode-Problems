class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int rem) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==0 && rem<=1 || nums[0]==1 && rem==0) return true;
            return false;
        }
        int canPlace=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(i+1<n && nums[i]==0 && nums[i+1] == 0){
                    canPlace++;
                    nums[i]=1;
                }
            }else if(i>=1 && i<n-1){
                if(nums[i]==0 && nums[i-1] ==0 &&nums[i+1]==0){
                    canPlace++;
                    nums[i]=1;
                } 
            } else if(i==n-1 && i!=0){
                if(nums[i-1]==0 && nums[i]==0){
                    canPlace++;
                    nums[i]=1;
                }
            }
        }
        cout<<canPlace;
        return canPlace>=rem;
    }
};