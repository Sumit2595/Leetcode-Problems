class Solution {
public:
    string convert(string s, int n) {
        vector<char>arr[n];
        int len=s.length();
        int idx=0,turn=0;
        while(idx<len){
            if(turn%2==0){
                for(int i=0;i<n && idx<len;i++){
                    arr[i].push_back(s[idx]);
                    idx++;
                }
            } else{
                for(int i=n-2;i>=1 && idx<len;i--){
                    arr[i].push_back(s[idx]);
                    idx++; 
                }
            }
            turn++;
        }
        string res="";
        for(auto a:arr){
            for(auto val:a){
                res+=val;
            }
        }
        return res;
    }
};