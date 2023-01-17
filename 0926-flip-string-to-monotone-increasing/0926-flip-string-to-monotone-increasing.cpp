class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeroToOnes=0,ones=0;
        int n=s.length();
        int i=0;
        while(i<n && s[i]=='0')
            i++;
        
        for(;i<n;i++){
            if(s[i]=='0'){
                zeroToOnes++;
            } else {
                ones++;
            }
            if(zeroToOnes>ones){
                zeroToOnes=ones;
            }
        }
        return zeroToOnes;
    }
};