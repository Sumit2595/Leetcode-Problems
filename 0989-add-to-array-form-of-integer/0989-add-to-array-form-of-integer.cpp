class Solution {
public:
    vector<int> solve(vector<int>& num,vector<int>& b){
       int m=num.size(),n=b.size();
        int i=m-1,j=n-1;
        int carry=0;
        vector<int>ans;
        while(i>=0 && j>=0){
            int sum=num[i]+b[j]+carry;
            carry=sum/10;
            ans.push_back(sum%10);
            i--;
            j--;
        }
        while(i>=0){
            int sum=num[i]+carry;
            carry=sum/10;
            ans.push_back(sum%10);
            i--;
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int temp=k;
        vector<int>b;
        while(temp){
            int rem=temp%10;
            temp/=10;
            b.push_back(rem);
        }
        reverse(b.begin(),b.end());
        int m=num.size(),n=b.size();
        if(m<n){
            return solve(b,num);
        }
        return solve(num,b);
    }
};