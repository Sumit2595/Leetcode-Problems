class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mp;
        int sz=banned.size();
        sort(banned.begin(),banned.end());
       for(auto b:banned)
           mp[b]++;
        int sum=0,numbers=0;
       for(int i=1;i<=n;i++){
           if(mp.find(i)==mp.end()){
               if(sum+i<=maxSum){
                   numbers++;
                   sum+=i;
               } else {
                   break;
               }
           }
       }
        return numbers;
    }
};