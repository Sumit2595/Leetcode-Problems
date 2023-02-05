class Solution {
public:
    int solve(int n){
        int temp=0;
        while(n){
            int rem=n%10;
            temp+=rem*rem;
            n/=10;
        }
        return temp;
    }
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        int slow=n;
        int fast=solve(n);
        while(fast!=1 && slow!=fast){
            slow=solve(slow);
            fast=solve(solve(fast));
        }
        return fast==1;
    }
};