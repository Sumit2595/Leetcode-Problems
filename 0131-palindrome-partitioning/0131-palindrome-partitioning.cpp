class Solution {
public:
    vector<vector<string>>ans;
    vector<string>temp;
    bool isPal(string s){
        int low=0,high=s.length()-1;
        while(low<=high){
            if(s[low]!=s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    void solve(string s,int idx,int n){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        for(int j=idx;j<n;j++){
            string str=s.substr(idx,j-idx+1);
            if(isPal(str)){
                temp.push_back(str);
                solve(s,j+1,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        solve(s,0,n);
        return ans;
    }
};