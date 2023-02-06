class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()>=0 && nums[i]>=0){
                st.push(nums[i]);
            } else if(!st.empty() && st.top() < 0){
                st.push(nums[i]);
            } else if(!st.empty() && st.top() >= 0 && nums[i]<0){
                int sz=abs(nums[i]);
                bool isSame=false;
                while(!st.empty() && st.top()>0 && st.top()<=sz){
                    if(st.top()==sz){
                        isSame=true;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(st.empty() && !isSame || !st.empty() && st.top() < 0 && !isSame){
                   st.push(nums[i]);
                }
            } else if(st.empty()){
                st.push(nums[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
       return ans;
    }
};