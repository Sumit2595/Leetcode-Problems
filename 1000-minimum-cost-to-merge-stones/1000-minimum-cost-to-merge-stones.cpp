class Solution {
public:
    vector<int> prefixSum = {0};
    int memo[32][32];
    int rec(vector<int>stones,int i,int j,int piles){
        if(i>=j)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        int res=INT_MAX;
        for(int k=i;k<j;k=k+piles-1){
            int temp=rec(stones,i,k,piles)+rec(stones,k+1,j,piles);
            res=min(res,temp);
        }
        if((j-i)%(piles-1)==0){
            res+=prefixSum[j+1]-prefixSum[i];
        }
        return memo[i][j]=res;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
		
		// If we can't merge all piles into 1 pile, so our answer is -1;
        if((n-1)%(k-1) != 0) return -1;
        memset(memo,-1,sizeof(memo));
        
        for(int i : stones) prefixSum.emplace_back(prefixSum.back() + i);
        return rec(stones, 0, n-1, k);
    }
};