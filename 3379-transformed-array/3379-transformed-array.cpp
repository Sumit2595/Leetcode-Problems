class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
         vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                int index=(i+nums[i])%n;
                result[i]=nums[index];
            } else {
               int temp=abs(nums[i])%n;
               int index=i-temp;
                if(index<0)
                    index+=n;
                result[i]=nums[index];
               cout<<index<<" ";
            }
        }
        return result;
    }
};