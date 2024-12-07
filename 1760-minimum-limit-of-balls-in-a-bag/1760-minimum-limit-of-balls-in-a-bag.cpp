class Solution {
public:
    bool check(vector<int>& nums,int divider,int ops){
        int n=nums.size();
        int i=0,count=0;
        while(i<n && ops > 0){
         if(nums[i] % divider == 0){
             count+=(nums[i]/divider)-1;
         } else {
             count+=(nums[i]/divider);
         }
            if(count > ops)
                return false;
            i++;
        }
        if(count > ops)
            return false;
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maximum=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int penalty=0;
        int low=1,high=maximum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,maxOperations)){
               penalty=mid;
               high=mid-1;   
            } else {
                low=mid+1;
            }
        }
        return penalty;
    }
};