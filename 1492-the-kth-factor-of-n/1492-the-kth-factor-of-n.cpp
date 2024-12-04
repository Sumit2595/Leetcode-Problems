class Solution {
public:
    bool isPerfectSquare(long long n)
    {
        if (ceil((double)sqrt(n)) == floor((double)sqrt(n))){
            return true;
        }
            
        return false;
    }
    int kthFactor(int n, int k) {
        int totalFactors=0;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0)
            totalFactors++;
        }
        totalFactors*=2;
        int ans;
        if(isPerfectSquare(n)){
            totalFactors--;
        }
        int first=1,last=totalFactors;
        for(int i=1;i*i<=n;i++){
            cout<<first<<" "<<last<<endl;
            if(n%i == 0){
              if(first == k)
                  return i;
              if(last == k)
                  return n/i;   
                first++;last--;
            }
        }
       return -1;
    }
};