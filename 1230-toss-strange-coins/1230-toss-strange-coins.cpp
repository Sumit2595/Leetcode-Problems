class Solution {
public:
    vector<vector<double>>dp;
    double solve(vector<double>& prob, int idx ,int target){
        if(idx>=prob.size())
            return 1.0;
        if(dp[target][idx]!=-1)
            return dp[target][idx];
        double ans=-1.0;
        if(target>0 and prob.size()-idx>target){
            ans=prob[idx] * solve(prob,idx+1,target-1)+ (1-prob[idx])*solve(prob,idx+1,target);
        } else if(target==0){
            ans=(1-prob[idx])*solve(prob,idx+1,target);
        } else if(target>0 and prob.size()-idx == target){
            ans=prob[idx] * solve(prob,idx+1,target-1);
        }
        return dp[target][idx]=ans;
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n=prob.size();
        dp=vector<vector<double>>(target+1,vector<double>(n,-1.0));
			if(prob.size()<target){
					return -1.0;
			}
        return solve(prob,0,target);
    }
};