class Solution {
public:
    unordered_map<int,int>mp;
    int solve(int n){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(mp.find(n)!=mp.end())
            return mp[n];
        return mp[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
       return solve(n);
    }
};