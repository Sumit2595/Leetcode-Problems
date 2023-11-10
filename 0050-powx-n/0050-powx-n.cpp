class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1){
            return 1;
        }
        double y=myPow(x,n/2);
        if(n<0)
        x=1/x;
        if(n%2==0)
            return y*y;
        return y*y*x;
    }
};