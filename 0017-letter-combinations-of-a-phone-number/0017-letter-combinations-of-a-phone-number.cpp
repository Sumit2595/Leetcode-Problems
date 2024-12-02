class Solution {
public:
    vector<string>pads={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void solve(string digit,int idx,string word){
        if(idx>=digit.size()){
            if(word.size())
             ans.push_back(word);
            return;
        }
        int x=digit[idx]-'0';
        cout<<x<<" ";
        for(int i=0;i<pads[x].length();i++){
            word+=pads[x][i];
            solve(digit,idx+1,word);
            word.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        solve(digits,0,"");
        return ans;
    }
};