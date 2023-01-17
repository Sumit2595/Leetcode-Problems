class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=n-2;i>=0;i--){
            right[i]=nums[i+1]*right[i+1];
            cout<<right[i]<<" ";
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=right[i];
            } else if(i==n-1){
                ans[i]=left[i];
            } else {
                ans[i]=left[i]*right[i];
            }
        }
      return ans;  
    }
};