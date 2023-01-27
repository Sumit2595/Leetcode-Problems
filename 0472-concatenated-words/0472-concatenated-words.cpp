class Solution {
public:
    unordered_map<string,int>mp;
    vector<string>ans;
    static bool cmp(string a,string b)
        {  return (a.length()>b.length());
        }
    bool solve(string word){
        int n=word.size();
        for(int i=1;i<n;i++){
            string temp=word.substr(0,i);
            string rem=word.substr(i,n-i);
            if(mp.find(temp)!=mp.end()){
                if(mp.find(rem)!=mp.end() || solve(rem)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        for(auto str:words){
            mp[str]++;
        }
        for(auto x:words){
            if(solve(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};