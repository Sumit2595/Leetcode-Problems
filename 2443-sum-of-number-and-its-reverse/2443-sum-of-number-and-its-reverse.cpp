class Solution {
public:
    int reverse(int n){
        int temp=0;
        while(n){
            int rem=n%10;
            temp=temp*10+rem;
            n/=10;
        }
        return temp;
    }
    bool sumOfNumberAndReverse(int num) {
         if(num==0){
            return true;
        }
        for(int i=num-1;i>=(num+1)/2;i--){
            int x=reverse(i);
            if(i+x == num){
                return true;
            }
        }
        return false;
    }
};