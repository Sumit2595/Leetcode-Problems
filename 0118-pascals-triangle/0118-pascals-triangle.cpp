class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans={{1}};
        int row=1;
        while(row<n){
            vector<int>prev=ans[row-1];
            vector<int>temp;
            temp.push_back(1);
            for(int i=0;i<prev.size()-1;i++){
                temp.push_back(prev[i]+prev[i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            row++;
        }
        return ans;
    }
};