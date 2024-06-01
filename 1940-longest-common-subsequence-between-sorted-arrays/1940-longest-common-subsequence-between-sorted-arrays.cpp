class Solution {
public:
    vector<int>getCommonArray(vector<int>v1,vector<int>v2){
        int i=0,j=0,m=v1.size(),n=v2.size();
        vector<int>common;
        while(i<m && j<n){
            if(v1[i] == v2[j]){
                common.push_back(v2[j]);
                i++;
                j++;
            } else if(v1[i]<v2[j]){
                 i++; 
            } else{
                j++;
            }
        }
        return common;
    }
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int>ans=arrays[0];
        int row=arrays.size();
        for(int i=1;i<row;i++){
            ans=getCommonArray(ans,arrays[i]);
        }
        return ans;
    }
};