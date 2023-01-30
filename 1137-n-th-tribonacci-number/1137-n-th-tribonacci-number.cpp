class Solution {
public:
    int tribonacci(int n) {
        if(n<=2){
            return n<=1?n:1;
        }
        int first=0,second=1,third=1,sum;
        for(int i=3;i<=n;i++){
            sum=first + second +third;
            first=second;
            second=third;
            third=sum;
        }
        return sum;
    }
};