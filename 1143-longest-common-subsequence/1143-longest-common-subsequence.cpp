class Solution {
public:
    vector<vector<int>>dp;
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return backtrack(text1,text2,0,0);
    }
    
    int backtrack(string &str1,string &str2,int i,int j){
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i==str1.length() || j==str2.length()) return 0;
        
        if(str1[i]==str2[j])
            return dp[i][j]= 1+backtrack(str1,str2,i+1,j+1);
        else
            return dp[i][j]= max(backtrack(str1,str2,i+1,j),backtrack(str1,str2,i,j+1));
    }
    
};