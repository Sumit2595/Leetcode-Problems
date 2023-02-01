class Solution {
public:
    bool isDivisible(string str,int len,string divisor){
        int n=str.length();
        int i=0;
        while(i<n){
            string dividend = str.substr(i,len);
            i+=len;
            if(dividend != divisor){
                return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        int m=str1.length(),n=str2.length();
        if(m<n){
            gcdOfStrings(str2,str1);
        }
        for(int i=0;i<n;i++){
            string divisor=str2.substr(0,i+1);
            int len=divisor.length();
            if(isDivisible(str1,len,divisor) && isDivisible(str2,len,divisor)){
               ans.clear();
                ans+=divisor;
            }
        }
        return ans;
    }
};