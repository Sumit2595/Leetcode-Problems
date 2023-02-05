class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int m=first.size(),n=second.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<m && j<n){
            int l1=first[i][0],l2=first[i][1];
            int r1=second[j][0],r2=second[j][1];
           if((r1<=l1 && l1<=r2)||(l1<=r1 && r1<=l2))
           {  int x=max({l1,r1});
               int y=min({l2,r2});
             ans.push_back({x,y});
           }
           if(l2<r2)
             i++;
           else if(l2>r2)
               j++;
           else{
                   i++;
                   j++;
           }
        }
        return ans;
    }
};