class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
         vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(i);
            else {
                if(prices[st.top()]<prices[i])
                    st.push(i);
                else{
                    while(!st.empty() && prices[st.top()] >= prices[i]){
                        ans[st.top()]=prices[st.top()]-prices[i];
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            ans[st.top()]=prices[st.top()];
            st.pop();
        }
        return ans;
    }
};