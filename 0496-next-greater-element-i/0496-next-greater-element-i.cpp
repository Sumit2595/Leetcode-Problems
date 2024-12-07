class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && nums2[i] >=st.top()){
                    st.pop();
                }
            }
          mp[nums2[i]]=st.empty() ? -1 : st.top();  
          st.push(nums2[i]); 
        }
        vector<int>nge;
        for(auto num:nums1){
            nge.push_back(mp[num]);
        }
        return nge;
    }
};