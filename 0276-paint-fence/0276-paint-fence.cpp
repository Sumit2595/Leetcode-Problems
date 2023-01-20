class Solution {
public:
    int numWays(int n, int k) {
        if(n==1)
            return k;
        int lastTwoSame=k,lastTwoDiff=k*(k-1),total=0;
        total=lastTwoSame+lastTwoDiff;
        for(int i=2;i<n;i++){
            lastTwoSame=lastTwoDiff;
            lastTwoDiff=total*(k-1);
            total=lastTwoDiff+lastTwoSame;
        }
        return total;
    }
};