class Solution {
    public long numberOfWays(String s) {
        int n=s.length();
        long dp[][][]=new long[n][4][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=-1;

                }
            }
        }
        return helper(s,n-1,0,'2',dp);

    }

    private long helper(String s,int ind,int len,char prev,long dp[][][]){
        if(len==3)
        return 1;

        if(ind<0)
        return 0;

        if(dp[ind][len][prev-'0']!=-1)
        return dp[ind][len][prev-'0'];

        long notPick=helper(s,ind-1,len,prev,dp);
        long pick=0;

        if(prev!=s.charAt(ind))
        pick=helper(s,ind-1,len+1,s.charAt(ind),dp);


        return dp[ind][len][prev-'0']=pick+notPick;

    }
}