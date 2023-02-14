class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.length(),n=b.length();
        if(m<n){
            return addBinary(b,a);
        }
        int i=m-1,j=n-1;
        string ans="";
        int carry=0;
        while(i>=0 && j>=0){
            if(a[i] == '1' && b[j] == '1'){
                if(carry){
                    ans+="1";
                } else {
                    ans+="0";
                }
                carry=1;
            } else if(a[i]=='0' && b[j]=='1' || a[i]=='1' && b[j]=='0'){
                if(carry == 0){
                    ans+="1";
                } else {
                    ans+="0";
                    carry=1;
                }
            } else if(a[i]=='0' && b[j]=='0'){
                if(carry){
                    ans+="1";
                } else {
                    ans+="0";
                }
                carry=0;
            }
            i--;j--;
        }
        while(i>=0){
            if(carry){
                if(a[i] == '1'){
                    ans+="0";
                    carry=1;
                } else {
                    ans+="1";
                    carry=0;
                }
            } else{
               if(a[i] == '1'){
                    ans+="1";
                } else {
                    ans+="0";
                } 
                carry=0;
            }
            i--;
        }
        if(carry){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};