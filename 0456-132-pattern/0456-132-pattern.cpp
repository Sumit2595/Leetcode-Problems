class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return false;
        vector<int>minim(n);
        stack<int>st;
        minim[0]=nums[0];
        for(int i=1;i<n;i++){
            minim[i]=min(nums[i],minim[i-1]);
        }
        for(int j=n-1;j>=0;j--){
            while(!st.empty() && st.top()<=minim[j]){
                st.pop();
            }
            if(!st.empty() && st.top()<nums[j])
                return true;
            st.push(nums[j]);
        }
        return false;
    }
};