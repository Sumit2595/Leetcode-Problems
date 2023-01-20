class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<int,vector<string>>mp;
        mp[1]={"0","1","8"};
        mp[2]={"11","69","88","96"};
        if(n==1)
            return mp[1];
        if(n==2)
            return mp[2];
        mp[2].push_back("00");
        for(int i=3;i<=n;i++){
            vector<string>temp;
            for(auto l:mp[i-2]){
                temp.push_back("1"+l+"1");
                temp.push_back("6"+l+"9");
                temp.push_back("8"+l+"8");
                temp.push_back("9"+l+"6");
            }
            if(i==n)
                return temp;
            for(auto l:mp[i-2]){
                temp.push_back("0"+l+"0");
            }
            mp[i]=temp;
        }
        return mp[n];
    }
};