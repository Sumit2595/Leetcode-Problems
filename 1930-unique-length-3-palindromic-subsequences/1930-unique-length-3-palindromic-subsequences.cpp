class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++)
        {   if(mp.find(s[i])==mp.end())
               mp[s[i]]={i,i};
            else
               mp[s[i]].second=i;
        }
        int count=0;
       for(auto x:mp)
       {  int i=x.second.first; //start
          int j=x.second.second; //end
          if(j-i>=2)
          {  set<char>st;
              for(int k=i+1;k<j;k++)
                 st.insert(s[k]);
           count+=st.size();
          }
       }
       return count; 
    }
};