class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       int n=nums.size();
       int end=-1,start=0;
       int maxim=nums[0];
       for(int i=1;i<n;i++){
           if(nums[i]<maxim){
               end=i;
           } else{
               maxim=nums[i];
           }
           
       }
       int minim=nums[n-1];
       for(int i=n-2;i>=0;i--){
           if(nums[i]>minim){
               start=i;
           } else {
               minim=nums[i];
           }
       }
      
       return end-start+1; 
    }
};